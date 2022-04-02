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
/* this function finds the first occurrence of character c in the string pointed to by pointer s, and 
 * returns a pointer to that position. Very similar to strchr, except that strchr expects a null terminated
 * string whereas memchr doesn't and hence needs a length parameter ('size'). Strchr can't search past a 
 * null character whereas memchr can...*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	/*while we haven't yet reached the stopping point of size bytes...*/
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
		/* if the value at s[i] is the same as the value of c, continue iterating through the 
		 * string. Now the notation: the first * means the dereferenced value of...and the 
		 * (unsigned char *) is casting s to an unsigned char pointer rather than const void. The
		 * (s + i) is another type of notation for s[i], ie, s[i] is the same as *(s + i). It means
		 * the dereference of the value in the array 'i' points away from the original start spot
		 * where s points. See below for alternate, but messier, notation.
		 * So why do we need to cast to unsigned char? Because a void pointer always needs to be
		 * cast to something (as it is used kind of as a placeholder/generic pointer able to 
		 * point to any data type, but cannot be dereferenced.) Could be cast to unsigned char or 
		 * signed char (I think) but unsigned is the simpler type */
			return ((void *)s + i);
			/* return a pointer now cast to void again (prototype wants void pointer) pointing to
			 * the position of this first occurrence of c.*/ 
		i++;
	}
	return (NULL);
	/*if the whole string has been iterated through up until size, and c hasn't been found, return 
	 * null */
}
/*Alternative code (difference at the if statement line). This is alternative notation for casting 
 * the pointer. */

void	*ft_memchr(const void *s, int c, size_t size)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        if (((unsigned char *)s)[i] == (unsigned char)c)
	/* if it were written as (unsigned char *)s[i] it doesn't work, because due to order of operations
	 * type thing, it would try to dereference s[i] first before casting the pointer to unsigned char
	 * rather than void. And it's impossible to dereference a void pointer. But, with an extra set of
	 * brackets: ((unsigned char *)s)[i] it casts the pointer first, then dereferences it.*/
                return ((void *)s + i);
        i++;
    }
    return(NULL);
}
