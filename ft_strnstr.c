/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:31:15 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 13:08:58 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function filters through the string 'haystack' and looks for the first occurrence of the string 'needle' 
 * within the haystack string. It will check until len bytes have been checked. It returns a pointer to the
 * newly found needle string (if found). If the needle string is not found, it returns a null pointer (as per
 * the man). If the needle string is null (empty), it returns a char pointer to haystack (as per man).*/
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[i])
		return ((char *)haystack);
	/*if needle string is empty/contains null, return a pointer to haystack, cast to char rather than const
	 * char (as that's what prototype demands)*/
	while (haystack[i] && i < len)
	/* while we haven't reached the null terminator of haystack, and while we haven't reached len...*/
	{
		j = 0;
		if (haystack[i] == needle[j])
		/* initially, j and i are both set to 0. This if statement checks if the value at position i in
		 * haystack is the same as in position j in needle: if this is the case, it could possibly be 
		 * the start of the first occurrence of needle string. If they are not the same, it will continue
		 * iterating through haystack until a character is found to match the start of needle.*/
		{
			while (haystack[i + j] == needle[j] && i + j < len)
			/* so thus far, we have the first character in needle, located in haystack. Next we begin
			 * incrementing j while keeping i positioned at the start of the (possible) occurrence of
			 * needle string within haystack, so that if we do in fact find needle there we can 
			 * return a pointer to i (the start of needle within haystack). So, while the value in 
			 * position (i + j) in haystack is the same as the value in position (j) in needle (ie 
			 * while the spot we've found in haystack continues to be identical to the needle 
			 * string) and while i + j combined hasn't reached len (ie we haven't
			 * reached the spot we want to stop checking at) we continue to increment j and check 
			 * along the haystack string, checking at each increment whether the value at that 
			 * position is still identical to the value at the equivalent position in needle.*/
			{
				if (needle[j + 1] == '\0')
					return ((char *)&haystack[i]);
				/* if we find the entire needle string within haystack ('success'!) the next 
				 * value after the last character in needle should be the null terminator of 
				 * needle string. This is how we know we have found the entire needle string 
				 * within haystack. Thus, we return a casted char pointer (rather than const
				 * char, as the function prototype demands a char pointer) pointing to the spot 
				 * in haystack (i) where the occurrence of needle string begins.*/
				j++;
				/*(but, if we haven't reached the end of needle yet, keep moving along via j)*/
			}
		}
		i++;
		/*however if the while loop is broken, either because the values are no longer the same or 
		 * because we have reached len, we will increment i by one and see if we are still within the 
		 * bounds of the outer while loop: ie, if we haven't reached the end of haystack or len. If
		 * that's still okay, we will see if we qualify for the if statement: whether the values at 
		 * that position in needle and haystack match. If not, we will not enter the inner while loop
		 * and will instead increment i again. This will continue until either the outer while loop 
		 * is broken (reached the end of haystack or reached len) in which case null is returned, or
		 * until we have qualified for the if statment again with another possible instance of needle 
		 * string within haystack string (ie the first character matches. Will then go through same 
		 * process of checking subsequent characters to see if they continue to match) */ 
	}
	return (NULL);
}
