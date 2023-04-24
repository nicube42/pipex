/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:06:56 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/24 19:47:12 by nicolasdiam      ###   ########.fr       */
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
	i = -1;
	while (vars->splitted_path[++i])
		vars->splitted_path[i] = ft_strjoin(vars->splitted_path[i], "/");
	vars->cmd1 = ft_split(av[2], ' ');
	vars->cmd2 = ft_split(av[3], ' ');
	//a proteger
}
