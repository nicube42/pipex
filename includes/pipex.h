/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:22:03 by ndiamant          #+#    #+#             */
/*   Updated: 2023/05/02 09:45:34 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft_printf/includes/libft.h"
# include "../libft_printf/includes/ft_printf.h"

typedef struct s_pipe
{
	char	**envp;
	char	**av;
	int		ac;
	int		infile;
	int		outfile;
	char	**cmd1;
	char	**splitted_path;
	char	**cmd2;
	char	*pathcmd1;
	char	*pathcmd2;
	int		end[2];
	pid_t	id;
	pid_t	id2;
	int		error;

}t_pipe;

int			main(int ac, char **av, char **envp);

void		ft_parsing_execve(t_pipe *vars);
void		ft_pipex(t_pipe *vars);

void		ft_error(char *error_msg, t_pipe *vars);
void		ft_free_tab(char **tab);
int			ft_check_cmd1_exist(t_pipe *vars);
int			ft_check_cmd2_exist(t_pipe *vars);
void		ft_free_all(t_pipe *vars);

#endif
