/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:36:32 by ndiamant          #+#    #+#             */
/*   Updated: 2023/05/01 18:32:55 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *error_msg, t_pipe *vars)
{
	perror(error_msg);
	ft_free_all(vars);
	exit(1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	tab = NULL;
}

void	ft_free_all(t_pipe *vars)
{
	if (vars->cmd2[0])
		ft_free_tab(vars->cmd2);
	if (vars->cmd1[0])
		ft_free_tab(vars->cmd1);
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
		if (access(cmd, F_OK) == 0)
		{
			vars->pathcmd1 = cmd;
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
		if (access(cmd, F_OK) == 0)
		{
			vars->pathcmd2 = cmd;
			free(cmd);
			return (1);
		}
		free(cmd);
	}
	return (0);
}
