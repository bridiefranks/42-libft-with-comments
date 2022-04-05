/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:35:42 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 14:13:41 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function takes a string, allocates (with malloc) enough memory to then store a substring made from
 * the original string, starting at the start index and finishing either at len bytes from the start of the
 * substring, or at the end of the original string (whichever comes first). It returns a pointer to the 
 * new substring.*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
/*s = the string from which to create the substring. start = the start index of the substring in the string
 * 's'. len = the maximum length of the substring.*/	
{
	char	*result;
	size_t	i;
	size_t	remain;

	if (start > ft_strlen(s))
		remain = 0;
	/* if the spot we are supposed to be starting from is larger than the length of the string (s), we
	 * set remain to 0 (because there is no string remaining after the start spot)*/
	else
		remain = ft_strlen(&s[start]);
	/*otherwise, if start is within the length of the string, we set remain to be the string length from
	 * start point onwards. Ft_strlen takes a pointer to the start of the string we want to know the 
	 * length of. So if we give it a pointer to the 'start' point, it will tell us how long the rest of
	 * the string is, starting at 'start'. The notation &s[start] is a pointer because the value of a
	 * pointer is the address (&) of the thing it's pointing at, and we want it to be pointing at the
	 * dereferenced value at position 'start' in the s string.*/
	if (remain < len)
		len = remain;
	/* if the amount remaining is less than len (which would mean len is larger than the string length),
	 * set len to equal remain. This bit of the code essentially just ensures the variable len becomes
	 * equal to whichever comes first: len, or how much string is remaining. So will either be the end 
	 * of the string or somewhere before the end.*/
	result = (char *)malloc(sizeof(char) * len + 1);
	/* allocate enough memory for len + 1 (bc terminating null) chars. It doesn't actually need
	 * to be typecast to char pointer as result is already a char pointer..*/
	i = 0;
	if (result == NULL)
		return (NULL);
	/*if the memory allocation was unsuccessful, and malloc returned a null pointer, ft_substr returns
	 * null*/
	while (i < len)
	/* while we haven't reached len (which remember is now either what it was originally, if it was 
	 * shorter than the remaining length of string, or equal to variable remain, if it were longer.*/
	{
		result[i] = s[start + i];
		i++;
		/*set the value at position i in the new substring (pointed to by result) equal to the value
		 * at position start + i in the original string (pointed to by s). Incremenet i.*/
	}
	result[i] = '\0';
	/*stick a null on the end of the substring*/
	return (result);
	/*return a pointer to the substring*/
}
