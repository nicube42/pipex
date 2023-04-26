/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:36:32 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/26 16:00:24 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *error_msg)
{
	ft_printf("Error : %s\n", error_msg);
	exit(1);
}

void	ft_parsing_execve(t_pipe *vars)
{
	int	i;

	i = 0;
	while (vars->envp[++i])
	{
		if (!ft_strncmp(vars->envp[i], "PATH=", 5))
			vars->path = vars->envp[i] + 5;
	}
	vars->splitted_path = ft_split(vars->path, ':');
	i = -1;
	while (vars->splitted_path[++i])
		vars->splitted_path[i] = ft_strjoin(vars->splitted_path[i], "/");
	vars->cmd1 = ft_split(vars->av[2], ' ');
	vars->cmd2 = ft_split(vars->av[3], ' ');
}

void	ft_open_in_create_out(t_pipe *vars)
{
	vars->infile = open (vars->av[1], O_RDONLY);
	if (vars->infile < 0)
		ft_error("input open error");
	vars->outfile = open(vars->av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (vars->outfile < 0)
		ft_error("output open error");
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
