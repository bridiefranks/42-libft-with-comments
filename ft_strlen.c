/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:12:28 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/22 13:07:24 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function works out how long a string of characters is. It does not count the terminating null character.
 * It returns the length as a size_t type, which is an unsigned data type used to represent the size of an object
 * (e.g. string length in bytes). Unlike int type, it is guaranteed to be large enough (has enough bytes) to represent
 * the size of any type.
 * Size_t is included in stdlib.h (see header file)
 * The string being counted is of type const char, pointed to by the const char pointer c. As the string is made up of 
 * chars, which are 1 byte each, the counter i therefore iterates along at 1 byte increments and thus the returned (i)
 * gives the length of the string in the number of bytes. */
#include "libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}
