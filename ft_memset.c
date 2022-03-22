/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:13:26 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/22 13:22:45 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function writes n bytes of value c (converted to unsigned char) to the string pointed to by b.
 * For example, if c were 'A' and n were '5' it would fill the string with 'AAAAA'.
 * It returns a void pointer b. A void pointer is a generic type of pointer which can point to any data type.
 * A void pointer can then be type casted into a particular type later, e.g. a char type.*/
#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*p;
	/* An unsigned char pointer is used, as the goal is to fill the string byte-wise. A void pointer gives no
	 * information as to how many bytes the counter i should move along each iteration. Whereas, unsigned chars 
	 * are 1 byte big and we want to move through the string 1 byte at a time. So using this type of pointer tells
	 * the counter which size increments to use.*/
	size_t			i;
	/*size_t used as it is measuring the size of an objet (in bytes). Also, n is of size_t type and thus i must be of
	 * the same type, as later in the function it is compared to n: (while (i < n)) -- this won't work if they are 
	 * different types.

	p = b;
	/*setting the pointer p to = b. Means p is now pointing at the same string as b*/
	i = 0;
	while (i < n)
		/*iterate through the string until you've reached the limiting n length specified*/
	{
		p[i] = (unsigned char)c;
		/*This line type casts the int c into unsigned char type. This is because we want n bytes of value c, and unsigned
		 * chars are 1 byte whereas ints are 4 bytes. And the string is pointed to by unsigned char pointer p.
		 * So it sets the value at i position in the string to the casted unsigned char value c.*/
		i++;
	}
	return (b);
	/*returns a pointer to the string now filled with value c (up until n).
}
