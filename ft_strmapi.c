/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:40:42 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 15:19:49 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Look at ft_striteri before looking at this function- it is a simpler version.
 * This function applies the function 'f' to each character of the string s, and makes a new string
 * (with malloc) made from the outputs of each successive application of f to the old string. For 
 * example, if the original string (s) were '4223' and the function f was to double each number, the new
 * string (str) would be '8446'. We don't actually know what f does though- it's a stand in for whatever
 * we might want the function to be, in application. I think we are writing this code more to give an
 * example of how passing functions as arguments can be used.*/
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
/* so the main takeaway from writing this function is to learn this new prototype structure. Here we see
 * a const char pointer s, pointing to the string we are iterating through (like normal). But there is 
 * also a char pointer to the function f in the prototype, plus the variables we are passing to f: an
 * unsigned int (the index position i), and a char (the value in the string at that position i). We don't
 * actually know what f will do with these, as f is not written here.*/
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	/*if the string is empty, return null*/
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	/* allocate enough memory to take a copy of the string ie a char type, with the string length of
	 * s spots, plus one for the null terminator. Note that the pointer (str) to this newly allocated
	 * memory doesn't actually need to be cast to be a char pointer, as it already is declared as one
	 * anyway (so could leave out the (char *) bit)*/
	if (str == NULL)
		return (NULL);
	/* if the memory allocation failed, if the heap was too full, malloc will return a null pointer 
	 * (ie the pointer str will be null) and ft_strmapi will return null.*/
	while (s[i])
	/*while we havn't reached the end of the string s (the null terminator)...*/
	{
		str[i] = f(i, s[i]);
		i++;
		/* set the value at position i in str to equal the value at position i in s, once f has
		 * been applied to it, and keep doing this for each position in the string s*/
	}
	str[i] = '\0';
	/* stick a null terminator on the end of str*/
	return (str);
	/* and return a pointer str to this new string.*/
}
