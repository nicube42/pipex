/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:06:56 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/24 17:34:22 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_parsing_execve(t_pipe *vars, char **av, char **envp)
{
	int	i;

	i = 0;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			vars->path = envp[i] + 5;
	}
	vars->splitted_path = ft_split(vars->path, ':');
	vars->cmd1 = ft_split(av[2], ' ');
	//a proteger
}