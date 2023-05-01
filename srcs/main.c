/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:11:07 by ndiamant          #+#    #+#             */
/*   Updated: 2023/05/01 18:43:31 by nicolasdiam      ###   ########.fr       */
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
	vars.infile = open (vars.av[1], O_RDONLY);
	if (vars.infile < 0)
		ft_error("input open error", &vars);
	vars.outfile = open(vars.av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (vars.outfile < 0)
		ft_error("output open error", &vars);
	if (ac != 5)
	{
		ft_printf("4 args needed <input> <cmd1> <cmd2> <output>\n");
		free(vars.cmd1);
		free(vars.cmd2);
		exit(1);
	}
	ft_parsing_execve(&vars);
	ft_pipex(&vars);
	exit(0);
}
