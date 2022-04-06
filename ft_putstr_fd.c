/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:47:08 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/10 17:27:16 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* see ft_putchar_fd for details. This function is the same, except it writes a string instead of one
 * char.*/
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	/* (this time, we don't give it '&s' like we did for the char &c, because s is already a pointer. 
	 * And the number of bytes required is found by calling ft_strlen on s.) */
}
