/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:34:23 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 14:04:56 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function takes a string, allocates sufficient memory to copy that string into, then copies the 
 * string into the allocated memory space. It returns a pointer to the new string location. */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*ptr;
	unsigned int	i;

	size = ft_strlen(s1);
	/* set the size variable to the leng of the original s1 string (to then use in malloc)*/
	ptr = malloc((size + 1) * sizeof(char));
	/* allocating memory with size + 1 (because of the null at the end) multiplied by the size of char,
	 * which is one byte per char. (We know it is char as that is what is described in the function 
	 * description/in the prototype). The pointer ptr points at this allocated space.*/
	i = 0;
	if (!ptr)
		return (NULL);
	/*if the memory allocation was unsucessful, because the heap was too full, malloc will return a null
	 * pointer. If this is the case, ft_strdup will return null.*/
	while (s1[i])
	/* while the value at position i in the original (s1) string is not null...*/
	{
		ptr[i] = s1[i];
		i++;
		/* set the value at position i in the new string location (pointed to by ptr) to be equal to
		 * the value at position i in the original string location (pointed to by s1) and continue
		 * iterating*/
	}
	ptr[i] = '\0';
	/*stick a null at the end*/
	return (ptr);
	/* return a pointer to this newly filled out string*/
}
