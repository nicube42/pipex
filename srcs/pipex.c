/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:57:22 by ndiamant          #+#    #+#             */
/*   Updated: 2023/05/01 18:48:40 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

void	ft_parsing_execve(t_pipe *vars)
{
	int		i;
	char	*full_path;

	i = 0;
	while (vars->envp[++i])
	{
		if (!ft_strncmp(vars->envp[i], "PATH=", 5))
			full_path = vars->envp[i] + 5;
	}
	vars->splitted_path = ft_split(full_path, ':');
	i = -1;
	while (vars->splitted_path[++i])
		vars->splitted_path[i] = ft_strjoin(vars->splitted_path[i], "/");
}

void	ft_pipex(t_pipe *vars)
{
	if (pipe(vars->end) < 0)
		ft_error("piping error", vars);
	vars->id = fork();
	if (vars->id < 0)
		ft_error("fork error", vars);
	else if (!vars->id)
		ft_child_process(vars);
	vars->id2 = fork();
	if (vars->id2 < 0)
		ft_error("fork error", vars);
	else if (!vars->id2)
		ft_child_process_2(vars);
	if (close(vars->end[0]) < 0)
		ft_error("close error", vars);
	if (close(vars->end[1]) < 0)
		ft_error("close error", vars);
	waitpid(vars->id, NULL, 0);
	waitpid(vars->id2, NULL, 0);
	ft_parent_process(vars);
}

static void	ft_child_process(t_pipe *vars)
{
	if (!ft_check_cmd1_exist(vars))
		ft_error("Pipex: command 1 not found", vars);
	if (dup2(vars->infile, STDIN_FILENO < 0))
		ft_error("dup2 error", vars);
	if (dup2(vars->end[1], STDOUT_FILENO < 0))
		ft_error("dup2 error", vars);
	if (close(vars->end[0]) < 0)
		ft_error("pipe close error", vars);
	if (close(vars->end[1]) < 0)
		ft_error("pipe close error", vars);
	if (execve(vars->pathcmd1, vars->cmd1, vars->envp) < 0)
		ft_error("error", vars);
}

static void	ft_child_process_2(t_pipe *vars)
{
	if (!ft_check_cmd2_exist(vars))
		ft_error("Pipex: command 2 not found", vars);
	if (dup2(vars->end[0], STDIN_FILENO) < 0)
		ft_error("dup2 error", vars);
	if (close(vars->end[1]) < 0)
		ft_error("pipe close error", vars);
	if (close(vars->end[0]) < 0)
		ft_error("pipe close error", vars);
	if (dup2(vars->outfile, STDOUT_FILENO) < 0)
		ft_error("dup2 error", vars);
	if (execve(vars->pathcmd2, vars->cmd2, vars->envp) < 0)
		ft_error("error", vars);
}

static void	ft_parent_process(t_pipe *vars)
{
	ft_free_all(vars);
	if (close(vars->infile) < 0)
		ft_error("input close error", vars);
	if (close(vars->outfile) < 0)
		ft_error("output close error", vars);
}
