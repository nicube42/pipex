/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:57:22 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/25 19:44:05 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

void	ft_pipex(t_pipe *vars)
{
	int	error;

	error = pipe(vars->end);
	if (error < 0)
		ft_error("piping error");
	vars->id = fork();
	if (vars->id < 0)
		ft_error("fork error");
	if (!vars->id)
		ft_child_process(vars);
	waitpid(vars->id, NULL, 0);
	ft_parent_process(vars);
}

void	ft_child_process(t_pipe *vars)
{
	int		fd2;
	int		i;
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
	ft_putstr_fd("Error : first command not found\n", 2);
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
	ft_putstr_fd("Error : second command not found\n", 2);
}