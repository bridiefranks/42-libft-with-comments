/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:36:55 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 14:20:45 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function joins two strings, s1 and s2, into one string (s2 stuck on the end of s1) that has space 
 * allocated for it by malloc. It returns a pointer to the new string.*/
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	i;
	char			*result;
	unsigned int	s1_len;
	unsigned int	s2_len;
	/* these variables are used to store the length of the two original strings*/

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
	/* allocate enough memory to store enough chars of the combined length of s1 and s2, plus one for 
	 * the null terminator. Set the pointer 'result' to point to this allocated memory. Doesn't actually
	 * need to be cast to a char pointer, even though malloc returns a void pointer, as the pointer
	 * result has already been declared a char pointer*/
	if (result == NULL)
		return (NULL);
	/* if the memory allocation wasn't successful, malloc will return a null pointer, and ft_strjoin
	 * will return null.*/
	while (i < s1_len)
	/*while we haven't yet reached the end of s1 string...*/
	{
		result[i] = s1[i];
		i++;
		/*set the value at position i in the new string to equal the value at position i in s1*/
	}
	while (i < s2_len + s1_len)
	/* while we haven't yet reached the combined length of s1 and s2...*/
	{
		result[i] = s2[i - s1_len];
		i++;
		/* set the value at i in the new string to equal the value at (i - the length of s1) in s2. 
		 * This is because we want i in result string to continue incrementing from where it got to
		 * previously (e.g. keep on iterating from position 16 or whatever) but want to iterate
		 * fromt the START of s2- so achieve this by subtracting the length of s1 from i. So for eg
		 * if s1 was 16 long, we would start counting in s2 from 16 - 16 = 0. */
	}
	result[i] = '\0';
	/*stick a null on the end*/
	return (result);
	/*return a pointer to the new string*
}
