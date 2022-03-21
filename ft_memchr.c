/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:28:40 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 10:47:37 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
/ still don't know why my notation doesn't work, still don't
/ know why we don't have to consider the size being longer 
/than the length of the array.
/answer: it's pesky notation- order of operations type thing. The code below should
/now work, with its extra set of brackets ((unsigned char *)s)[i] -- ie the outside ones
/As opposed to original: (unsigned char *)s[i] ...where it tries to dereference i before 
/casting it, and can't cos it's void.


void	*ft_memchr(const void *s, int c, size_t size)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        if (((unsigned char *)s)[i] == (unsigned char)c)
                return &((unsigned char *)s)[i];
        i++;
    }
    return(NULL);
}
*/
