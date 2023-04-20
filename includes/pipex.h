/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:22:03 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/20 15:11:06 by ndiamant         ###   ########.fr       */
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
	int		infile;
	int		outfile;
	char	*cmd1;
	char	*path1;
	char	*cmd2;
	int		end[2];
	pid_t	parent;

}t_pipe;

int		main(int ac, char **av, char **envp);

void	ft_open_input(t_pipe *vars, char **av);
void	ft_pipex(t_pipe *vars, char **av, char **envp);

void	ft_error(void);

#endif
