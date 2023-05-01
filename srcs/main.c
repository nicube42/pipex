/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:11:07 by ndiamant          #+#    #+#             */
/*   Updated: 2023/05/01 14:45:32 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	vars;

	vars.ac = ac;
	vars.av = av;
	vars.cmd1 = ft_split(av[2], ' ');
	vars.cmd2 = ft_split(av[3], ' ');
	vars.envp = envp;
	if (ac != 5)
	{
		ft_error("4 args needed <input> <cmd1> <cmd2> <output>");
		exit(1);
	}
	ft_parsing_execve(&vars);
	ft_pipex(&vars);
	exit(0);
}
