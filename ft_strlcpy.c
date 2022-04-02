/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:20:46 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 10:32:49 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* this function copies from src to dst, up until the point where you have copied dstsize bytes. Returns
 * the length of src, not really sure why though?*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
	/*if the value of dstsize is 0, ie we aren't copying anything, return the length of src string (as
	 * per man)*/
	{
		return (ft_strlen(src));
	}
	while (i < dstsize - 1 && src[i])
	/* while we haven't yet reached dstsize (where we want to stop) (note it's 'dstsize - 1' because
	 * the i index starts at 0 whereas dstsize 'starts' at count 1) and, while src[i], which means 
	 * while the value at i is not null ie haven't reached the end of src yet...*/
	{
		dst[i] = src[i];
		i++;
		/*set the value at i in dst to = the corresponding value at i position in src, and 
		 * increment through src*/
	}
	if (i < dstsize)
	/* tbh I don't know why this is here ^ as surely after breaking out of the while loop, i will 
	 * always be < dstsize?*/
	{
		dst[i] = '\0';
		/* set the last value to null*/
	}
	return (ft_strlen(src));
	/*as ft_strlen is included in the libft.h header file, it is in that library and can therefore be
	 * referenced in this function so long as 'include libft.h' is at the top*/
}
