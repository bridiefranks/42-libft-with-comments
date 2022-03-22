/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:16:05 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/22 13:30:05 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function writes n bytes-worth of zeros into the string pointed to by s. If n = 0, bzero() does nothing
 * (i.e. returns nothing).*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	/*have to use an unsigned char pointer rather than the provided void pointer, as we want to move along the string
	 * in 1 byte increments- hence char, which are 1 byte. Using a pointer of this type tells the counter i to move along
	 * by 1 byte. Also, you can't dereference a void pointer (see while loop).*/
	size_t			i;
	/*size_t type for counter, as it represents the size of an object (string length) and is compared to n, which is of 
	 * size_t type.*/

	p = s;
	/*sets unsigned char pointer p to point to the same string as void pointer s*/
	i = 0;
	while (i < n)
		/* up until n...*/
	{
		p[i] = 0;
		/*fill the string with zeros*/
		i++;
	}
	return ;
	/* don't return anything (void). Could also just not have return in there at all.*/
}
