/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:30:21 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 12:33:14 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function is very similar to strncmp. It compares the first n bytes of 2 memory areas
 *  (pointed to by s1 and s2) loooking for any difference between the two (lexicographically). If the first
 *  differing character in s1 is greater than the equivalent character in s2, it returns a positive integer;
 *  if it is less in s1 than in s2 it returns a negative integer and if the two memory areas are identical a
 *  zero is returned. Memcmp can receive any type of pointer (to any data type) whereas strncmp works with
 *  strings of characters only. Strncmp can handle strings as it has a condition to stop at a terminating
 *  null character. Whereas, memcmp is just comparing a group of bytes, not necessarily a string, and doesn't
 *  stop at a null character (and so is able to continue checking even after a null character). You could 
 *  use it to compare strings if you knew how long they were (and used n accordingly) but otherwise it 
 *  wouldn't inherently know when to stop.*/ 
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;
	/*creating unsigned char pointers to then turn into unsigned char versions of the const void pointers
	 * s1 and s2*/

	ptr_1 = (unsigned char *)s1;
	ptr_2 = (unsigned char *)s2;
	/*setting the 2 new pointers to equal casted unsigned versions of the original pointers ie they now 
	 * point to the same spot.
	 * Not sure why skipping intermediate pointers (ptr_1 and ptr_2) and directly casting the original 
	 * pointers doesn't work- according to the internet it should. Ie doing this: s1 = (unsigned char *)s1;
	 * doesn't compile, with errors suggesting the pointers are still void type (saying void pointers
	 * can't be dereferenced).*/
	i = 0;
	while (i < n && ptr_1[i] == ptr_2[i])
	/* while we haven't yet reached n and while the values at position i are the same between the 2 memory
	 * areas, continue iterating through the memory areas...*/
	{
		i++;
	}
	if (i < n)
	/*if the while loop is broken due to the values no longer being the same (rather than i < n) this if 
	 * statement is fulfilled, and the returned integer will be the difference between the values at 
	 * position i, with a positive integer returned if prt_1 is greater, etc.*/
		return (ptr_1[i] - ptr_2[i]);
	return (0);
	/* otherwise, if the while loop breaks because n is reached and there have been no different characters
	 * (so the memory areas are identical) it will return a 0*/
}
