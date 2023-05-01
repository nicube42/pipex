/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:57:22 by ndiamant          #+#    #+#             */
/*   Updated: 2023/05/01 15:27:29 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

void	ft_pipex(t_pipe *vars)
{
	if (pipe(vars->end) < 0)
		ft_error("piping error");
	vars->id = fork();
	if (vars->id < 0)
		ft_error("fork error");
	else if (!vars->id)
		ft_child_process(vars);
	vars->id2 = fork();
	if (vars->id2 < 0)
		ft_error("fork error");
	else if (!vars->id2)
		ft_child_process_2(vars);
	close(vars->end[0]);
	close(vars->end[1]);
	waitpid(vars->id, NULL, 0);
	waitpid(vars->id2, NULL, 0);
	ft_parent_process(vars);
}

void	ft_child_process(t_pipe *vars)
{
	if (!ft_check_cmd1_exist(vars))
		ft_error("Pipex: command 1 not found");
	vars->infile = open (vars->av[1], O_RDONLY);
	if (vars->infile < 0)
		ft_error("input open error");
	dup2(vars->infile, STDIN_FILENO);
	dup2(vars->end[1], STDOUT_FILENO);
	close(vars->end[0]);
	close(vars->end[1]);
	if (execve(vars->pathcmd1, vars->cmd1, vars->envp) < 0)
		ft_error("error");
}

void	ft_child_process_2(t_pipe *vars)
{
	if (!ft_check_cmd2_exist(vars))
		ft_error("Pipex: command 2 not found");
	vars->outfile = open(vars->av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (vars->outfile < 0)
		ft_error("output open error");
	dup2(vars->end[0], STDIN_FILENO);
	close(vars->end[1]);
	close(vars->end[0]);
	dup2(vars->outfile, STDOUT_FILENO);
	if (execve(vars->pathcmd2, vars->cmd2, vars->envp) < 0)
		ft_error("error");
}

void	ft_parent_process(t_pipe *vars)
{
	ft_free_all(vars);
	close(vars->infile);
	close(vars->outfile);
}
