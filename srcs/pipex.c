/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:57:22 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/24 18:11:22 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_open_in_create_out(t_pipe *vars, char **av)
{
	vars->infile = open (av[1], O_RDONLY);
	if (vars->infile < 0)
		ft_error();
	vars->outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
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
	else
		ft_parent_process(vars);
}

void	ft_child_process(t_pipe *vars)
{
	int	fd2;
	int	i;
	char	*cmd;

	fd2 = dup2(vars->infile, STDIN_FILENO);
	dup2(vars->end[1], STDOUT_FILENO);
	i = -1;
	ft_printf("%s", vars->splitted_path[0]);
	while (vars->splitted_path[++i])
	{
		cmd = ft_strjoin(vars->splitted_path[i], vars->av[2]); // protect your ft_join
		ft_printf("%s", cmd);
		execve(cmd, vars->cmd1, vars->envp);
		free(cmd);
	}
	close(vars->end[0]);
	close(vars->infile);
}

void	ft_parent_process(t_pipe *vars)
{
	dup2(vars->outfile, STDOUT_FILENO);
	dup2(vars->end[0], STDIN_FILENO);
	close(vars->end[1]);
	close(vars->outfile);
}