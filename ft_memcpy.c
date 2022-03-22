/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:17:52 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/22 13:40:58 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function copies n bytes from src into dst. If src and dst overlap, behaviour is undefined (i.e. they shouldn't
 * overlap- if they do, or if they might, use memmove instead.)
 * The original value of dst is returned- the pointer pointing to dst.*/
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	/* unsigned char type pointer used, so that the counter i knows to move through the string 1 byte at a time*/
	const unsigned char	*s;
	/* same thing, except is 'const' as well, as the inputted pointer src is const void (if you drop the const it won't 
	 * like it! Are losing a qualifier. Const makes it a read-only variable. Makes sense as we aren't altering src, 
	 * just dst*/
	size_t				i;
	/* size_t type as it represents the size of an object, and is compared to n which is size_t*/

	d = dst;
	s = src;
	/* pointers d and s now point to dst and src respectively.*/
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		/*for every byte iteration through src string, set the value at position i in dst to be the same as the value at 
		 * position i in src*/
		i++;
	}
	return (dst);
	/*return (void) pointer to dst string*/
}
