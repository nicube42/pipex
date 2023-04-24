/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:11:07 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/24 17:40:31 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	vars;

	vars.ac = ac;
	vars.av = av;
	vars.envp = envp;
	/*if (ac != 5)
		ft_error();*/
	ft_open_in_create_out(&vars, av);
	ft_parsing_execve(&vars, av, envp);
	ft_pipex(&vars, av, envp);
	return (0);
}
