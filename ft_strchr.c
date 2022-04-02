/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:25:03 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 10:41:57 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function finds the first occurrence, if present, of character c in the string pointed to by s. 
 * It then returns a char pointer to the position of that occurrence, or null if the character is not 
 * found.*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	/* set variable len to be the length of the string, as len is a size_t variable and therefore can
	 * be used to compare i against (which is also size_t) */
	i = 0;
	while (i <= len)
	/* while we haven't reached the end of the string...*/
	{
		if (s[i] == (char)c)
		/* if the value at position i in the string is the same as the value of c, return a 
		 * pointer to that position. Note that c is typecast from int (what we receive as per 
		 * prototype) to char as 1. it is what the man says and 2. we want to return a char 
		 * pointer, which must by definition point to a char*/
			return ((char *)&s[i]);
		/* again, s is a const char pointer but we want to return a char pointer (see in prototype)
		 * and thus we typecast the pointer to be char. The notation is (char *)&s[i] rather than
		 * (char *)s[i] because the latter would be trying to typecast a char pointer to an actual 
		 * value (s[i]) (the dereferenced value at i in string s) (which is an incompatible 
		 * conversioin) rather than typecast a pointer to a pointer, which is correct. Ie 
		 * the & means the address and the value of a pointer is the address of the thing it is 
		 * pointing at, so, &s[i] is the address of s[i], which is a pointer*/ 
		i++;
	}
	return (NULL);
}
