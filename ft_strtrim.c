/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:38:16 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 14:41:39 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function takes a string, and trims off specific characters from either end, resulting in a new
 * trimmed and copied string (allocated with malloc). There can be more than one type of character that
 * gets trimmed off, but they have to be specified. These specific characters are stored within 'set'.
 * The static int function works out whether the character in the string matches one of the specified 
 * characters to trim, while the main ft_strtrim function does the actual making of the new string. A 
 * pointer to the new trimmed string is returned.*/ 
#include "libft.h"

static int	match(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	/* while we haven't reached the terminating null of the string 'set' (which contains the reference
	 * set of characters to trim)...*/
	{
		if (c == set[i])
			return (1);
		/* if the value in the string that we're checking is the same as the the first character in
		 * the reference list of trim characters, return 1. If not, iterate i to move to the next
		 * character in the reference list of trim characters, and check whether the value c in the
		 * string we're checking is the same as THAT trim character. Keep going until you've checked
		 * the character of interest against all the possible trim characters in set. */
		i++;
	}
	return (0);
	/* if the character we're checking doesn't match any of the reference trim characters, return 0*/
}

char	*ft_strtrim(const char *s1, const char *set)
/* set = the reference set of characters to trim. S1 = the string to be trimmed.*/

{
	int		front;
	int		back;
	int		i;
	char	*result;

	if (!(s1 || set))
		return ((char *)s1);
	/*if either the string 's1' or the string 'set' are empty, return a pointer to s1, cast to a 
	 * char pointer (rather than const char, as that's what the prototype specifies)*/
	front = 0;
	while (s1[front] && match(s1[front], set))
		front++;
	/*we use the counter 'front' to move along the s1 string from the start, in the forwards direction. 
	 * The 'back counter is later used to check from the end of s1 in the backwards direction (as we 
	 * want to trim from both ends). So, while the front counter hasn't reached the null terminator of
	 * s1, and while the character at position front is true as per match function (true = return 1 =
	 * means the character does match one of the characters in set)- iterate front counter. So the 
	 * counter 'front' moves through the start of the string, so long as it's passing characters 
	 * contained within set. As soon as it meets one that isn't one of those specified characters (or 
	 * hits the end) it'll stop */ 
	back = ft_strlen(s1);
	/*now we're doing the reverse, by setting the counter 'back' to start at the end of s1 string and
	 * iterate backwards instead */
	while (back > front && match(s1[back - 1], set))
		back--;
	/*same logic as other while loop, just backwards. Is [back - 1] because indexes always start at value
	 * zero whereas ft_strlen starts at value 1. So setting back to the strlen initially makes it 'one 
	 * too big' in terms of index count*/
	result = malloc((back - front + 1) * sizeof(*result));
	/* allocate enough memory for the new trimmed string that has the length of the position where back
	 * index got to, minus the position where front index got to, plus one for null terminator. It is 
	 * of type *result which means the dereference of result: as result is a char pointer, *result is
	 * what result is pointing to, which is chars. Could equally have put sizeof(char).*/
	if (!result)
		return (NULL);
	/* if the memory allocation was unsuccessful (if the heap was full), malloc will return a null 
	 * pointer and ft_strtrim will return null.*/
	i = 0;
	while (front < back)
		result [i++] = s1[front++];
	/*we are now using a new counter i to move through the newly created string, while the counter front
	 * moves through the original s1 string. While the counter front hasn't reached the counter back 
	 * (which would mean we have reached the end of the section we want to copy into the new string 
	 * 'result'), set the value at position i in result (starts at 0) to equal the value at position 
	 * front in s1. This notation is a bit different to what may have been seen before, where you set
	 * the value in one line and iterate the counter in the next. But does the same thing- sets 
	 * result[i] to equal s1[front], then iterates the respective counters. I believe if it were written
	 * result[++i] = s1]++front] it would iterate first THEN assign, which we don't want. So, this part
	 * of the code is where the new trimmed string is copied off the selceted section of the original
	 * string.*/
	result[i] = '\0';
	/* null terminator stuck on the end*/
	return (&result[0]);
	/*and a pointer to the 0th position in result (the trimmed string) is returned. This is actually 
	 * silly- just writing 'return (result)' is a better way...*/
}
