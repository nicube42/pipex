/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:44:01 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/17 16:14:08 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Ecrit le caractère 'c' sur le descripteur de fichier donné.
*/

#include <unistd.h>
#include "../../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
