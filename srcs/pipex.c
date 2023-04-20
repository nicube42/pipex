/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:57:22 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/20 14:05:01 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_open_input(t_pipe *vars, char **av)
{
	int	error;

	vars->infile = open (av[1], O_RDONLY);
	if (vars->infile < 0)
		ft_error();
	return (error);
}

void	ft_pipe()
{
	
}

int	main(int ac, char **av)
{
	t_pipe	vars;
	int		error;

	if (ac != 5)
		ft_error();
	ft_open_input(&vars, av);
	return (0);
}
