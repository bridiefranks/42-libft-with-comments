/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:27:24 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 11:43:50 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function compares string s1 and string s2 up to n bytes, for the first character that is 
 * different between the two strings. If this s1 character is greater than the equivalent s2 
 * character (in terms of ascii value) (ie lexicographically) it returns a positive integer; if this 
 * s1 character is equal to the s2 character it returns zero; and if the s1 character is less than the 
 * s2 character it returns a negative integer. The code achieves this by subtracting s2 from s1 (if s1 
 * is bigger, will be a positive number etc).
 * It will check in this way up until n bytes have been checked or until a differing character is found.*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	/*starting from the start of the strings...*/
	while (s1[i] && s2[i] == s1[i] && i < n)
	/* while we are not at the end (null character) of s1 yet, and while the value at the position i 
	 * is the same between both strings s1 and s2, and while we haven't yet reached n, keep moving 
	 * through the string*/
	{
		i++;
	}
	if (i < n)
	/* If the position where the while loop broke was less than n still, return the following 
	 * (negative or positive integer, or zero). Otherwise, if n has been reached without finding
	 * any discrepancies, just return zero*/
	{
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		/* return the value at position i of s1, minus the value at position i of s2. These 
		 * values are typecast to unsigned char rather than const char because unsigned char is
		 * the simplest form of char type- could also just be left as const char and that seems
		 * to work*/
	}
	return (0);
	/*if the strings are exactly the same (until n anyway) return 0 */
}
