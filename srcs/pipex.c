/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:57:22 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/20 15:03:24 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_open_in_create_out(t_pipe *vars, char **av)
{
	int	error;

	vars->infile = open (av[1], O_RDONLY);
	if (vars->infile < 0)
		ft_error();
	vars->outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars->outfile < 0)
		ft_error();
	return (error);
}

void	ft_pipex(t_pipe *vars, char **av, char **envp)
{
	int	error;

	error = pipe(vars->end);
	if (error < 0)
		ft_error();
	vars->parent = fork();
	if (vars->parent < 0)
		ft_error();
	if (!vars->parent)
		ft_child_process(vars);
	else
		ft_parent_process(vars);
}

void	ft_child_process(t_pipe *vars)
{

}

void	ft_parent_process(t_pipe *vars)
{

}