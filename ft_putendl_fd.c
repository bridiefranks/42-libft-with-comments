/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:48:15 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 10:49:04 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* see ft_putchar_fd for details. This function is the same except instead of writing a char, it writes
 * a string 's' and then puts a new line after it (so same as ft_putstr_fd except with a new line put at
 * the end)*/
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
