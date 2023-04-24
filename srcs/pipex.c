/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:57:22 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/24 19:53:52 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

void	ft_open_in_create_out(t_pipe *vars, char **av)
{
	vars->infile = open (av[1], O_RDONLY);
	if (vars->infile < 0)
		ft_error();
	vars->outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (vars->outfile < 0)
		ft_error();
}

void	ft_pipex(t_pipe *vars, char **av, char **envp)
{
	int	error;

	(void) av;
	(void) envp;
	error = pipe(vars->end);
	if (error < 0)
		ft_error();
	vars->id = fork();
	if (vars->id < 0)
		ft_error();
	if (!vars->id)
		ft_child_process(vars);
	waitpid(vars->id, NULL, 0);
	ft_parent_process(vars);
}

void	ft_child_process(t_pipe *vars)
{
	int	fd2;
	int	i;
	char	*cmd;

	fd2 = dup2(vars->infile, STDIN_FILENO);
	dup2(vars->end[1], STDOUT_FILENO);
	close(vars->end[0]);
	i = -1;
	while (vars->splitted_path[++i])
	{
		cmd = ft_strjoin(vars->splitted_path[i], vars->cmd1[0]); // protect your ft_join
		execve(cmd, vars->cmd1, vars->envp);
		free(cmd);
	}
}

void	ft_parent_process(t_pipe *vars)
{
	char	*cmd;
	int		i;

	dup2(vars->outfile, STDOUT_FILENO);
	dup2(vars->end[0], STDIN_FILENO);
	close(vars->end[1]);
	i = -1;
	while (vars->splitted_path[++i])
	{
		cmd = ft_strjoin(vars->splitted_path[i], vars->cmd2[0]); // protect your ft_join
		execve(cmd, vars->cmd2, vars->envp);
		free(cmd);
	}
}