/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:11:07 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/28 13:21:36 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	vars;

	vars.ac = ac;
	vars.av = av;
	vars.envp = envp;
	if (ac != 5)
	{
		ft_error("4 args needed <input> <cmd1> <cmd2> <output>");
		exit(1);
	}
	ft_open_in_create_out(&vars);
	ft_parsing_execve(&vars);
	if (!ft_check_cmd1_exist(&vars))
		ft_printf("Pipex: command not found: %s\n", vars.cmd1[0]);
	if (!ft_check_cmd2_exist(&vars))
		ft_printf("Pipex: command not found: %s\n", vars.cmd2[0]);
	if (!ft_check_cmd1_exist(&vars) || !ft_check_cmd2_exist(&vars))
	{
		exit(1);
	}
	ft_pipex(&vars);
	exit(0);
}
