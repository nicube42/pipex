/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:36:32 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/28 14:30:04 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *error_msg)
{
	perror(error_msg);
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

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
	}
	free(tab);
	tab = NULL;
}

int	ft_check_cmd1_exist(t_pipe *vars)
{
	int		i;
	char	*cmd;
	int		j;

	j = -1;
	i = -1;
	while (vars->splitted_path[++i])
	{
		cmd = ft_strjoin(vars->splitted_path[i], vars->cmd1[0]);
		if (access(cmd, X_OK) != -1)
		{
			vars->pathcmd1 = cmd;
			while (vars->cmd1[++j])
				vars->pathcmd1[j] = ft_strjoin(vars->pathcmd1, vars->cmd1[j]);
			free(cmd);
			return (1);
		}
		free(cmd);
	}
	return (0);
}

int	ft_check_cmd2_exist(t_pipe *vars)
{
	int		i;
	char	*cmd;

	i = -1;
	while (vars->splitted_path[++i])
	{
		cmd = ft_strjoin(vars->splitted_path[i], vars->cmd2[0]);
		if (access(cmd, X_OK) != -1)
		{
			vars->pathcmd2 = cmd;
			free(cmd);
			return (1);
		}
		free(cmd);
	}
	return (0);
}
