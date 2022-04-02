/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:22:21 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 10:37:55 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* this function sticks src onto the end of dst, until the concatenated dst+src string has reached
 *  dstsize bytes long. It returns the total length of the string it tried to create: the initial 
 *  length of dst plus the length of src. This result can be used to determine if the final string
 *  was truncated (ie if dstsize was less than the combined length of dst and src?). Unless, if 
 *  dstsize is < the length of dst, it will return the length of src plus dstsize (which in this 
 *  case is less than the length of dst). Not entirely sure why this return value is desired.*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)

{
	size_t	dsti;
	size_t	srci;
	/*these two variables are counters for the dst and src strings respectively*/
	size_t	tot_len;

	if (!dstsize)
	/*if dstsize is 0, just return the lenght of src*/
		return (ft_strlen(src));
	if (dstsize < ft_strlen(dst))
	/*as 'explained' above, don't really understand */ 
		tot_len = dstsize + ft_strlen(src);
	else
	{
		tot_len = ft_strlen(dst) + ft_strlen(src);
		/*in the typical circumstance, total length is the original length of dst plus the length
		 * of src. I think the idea is that dstsize is supposed to be exactly this total length,
		 * and if not, this return of total length is used to identify the truncation (?)*/
	}
	dsti = ft_strlen(dst);
	/*set dsti to be at the end of dst string, so that we start concatenating onto the end of dst*/
	srci = 0;
	/*whereas set srci to the start of src, as that's where we want to start copying from */
	while (src[srci] && dsti < dstsize - 1)
	/* while we haven't yet reached the end (null character) of src, and while the counter for dst 
	 * hasn't yet reached the designated position we want to stop copying at (ie dstsize- or in fact,
	 * dstsize - 1 as dsti counter starts at 0 not 1)...*/
	{
		dst[dsti] = src[srci];
		dsti++;
		srci++;
		/*set the value at dsti (initially at the end of dst) to be the value of srci (initially
		 * at the start of src) then increment through both strings*/
	}
	dst[dsti] = '\0';
	/*add a terminating null to the end*/
	return (tot_len);
	/*see above*/
}
