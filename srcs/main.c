/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:11:07 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/26 15:41:59 by nicolasdiam      ###   ########.fr       */
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
		ft_error("4 args needed <input> <cmd1> <cmd2> <output>");
	ft_open_in_create_out(&vars);
	ft_parsing_execve(&vars);
	ft_pipex(&vars);
	ft_free_tab(vars.cmd1);
	ft_free_tab(vars.cmd2);
	ft_free_tab(vars.splitted_path);
	return (0);
}
