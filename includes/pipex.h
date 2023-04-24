/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:22:03 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/24 19:07:10 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdlib.h>
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
	char	*path;
	char	**splitted_path;
	char	**cmd2;
	int		end[2];
	pid_t	id;

}t_pipe;

int		main(int ac, char **av, char **envp);

void	ft_open_in_create_out(t_pipe *vars, char **av);
void	ft_pipex(t_pipe *vars, char **av, char **envp);

void	ft_child_process(t_pipe *vars);
void	ft_parent_process(t_pipe *vars);

void	ft_error(void);

void    ft_parsing_execve(t_pipe *vars, char **av, char **envp);

#endif
