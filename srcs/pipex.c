/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:57:22 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/28 14:12:29 by ndiamant         ###   ########.fr       */
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
	waitpid(vars->id, NULL, 0);
	waitpid(vars->id2, NULL, 0);
	ft_parent_process(vars);
}

void	ft_child_process(t_pipe *vars)
{
	dup2(vars->infile, STDIN_FILENO);
	dup2(vars->end[1], STDOUT_FILENO);
	close(vars->end[0]);
	if (execve(vars->pathcmd1, vars->cmd1, vars->envp) < 0)
		ft_error("error\n");
}

void	ft_child_process_2(t_pipe *vars)
{
	dup2(vars->end[0], STDIN_FILENO);
	dup2(vars->outfile, STDOUT_FILENO);
	close(vars->end[1]);
	if (execve(vars->pathcmd2, vars->cmd2, vars->envp) < 0)
		ft_error("error\n");
}

void	ft_parent_process(t_pipe *vars)
{
	ft_free_tab(vars->cmd2);
	ft_free_tab(vars->splitted_path);
	ft_free_tab(vars->cmd1);
	close(vars->infile);
	close(vars->outfile);
}

void	ft_open_in_create_out(t_pipe *vars)
{
	vars->infile = open (vars->av[1], O_RDONLY);
	if (vars->infile < 0)
		ft_error("input open error");
	vars->outfile = open(vars->av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (vars->outfile < 0)
		ft_error("output open error");
}
