/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:46:01 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/10 16:48:17 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function is like the ft_putchar we did in the piscine, except that there's an extra variable
 * fd used. This fd means file descriptor. A file descriptor is an integer that uniquely identifies an
 * open file in a computer's operating system. It describes a data resource, and how that resource may
 * be accessed. For example, we usually use the write function with the fd set to 1. this 1 refers to
 * the standard output- ie, we visibly see the written thing on our screen in the standard output. Other
 * examples include fd= 0 to represent the standard input, and fd=2 to represent the standard error. 
 * Having fd as a variable means we can choose what we want it to be. The concept is a bit confusing so
 * would recommend a google!
 * Anyway, the function takes a char 'c' and writes it, according to whatever fd is specified as. 
 * Nothing is returned as the function is void.*/
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	/* (we give the write function the address of c, and the amount of bytes required, which is one
	 * as c is a char)*/
}
