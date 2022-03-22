/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:19:24 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/22 14:16:53 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function copies len bytes from string src to string dst. This function is used when the 2 strings may overlap (contrast
 * memcpy). The copy is always done in a non-destructive manner
 * A pointer to the original value of dst is returned.*/
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;
	/* see descriptions in previous functions as to why we do this ^*/

	d = dst;
	s = src;
	if (d < s)
		/*if the position of dst in memory is 'less' or 'lower' than the position of src, we want to copy from src to dst
		 * in an upwards direction (left to right in pic below)
		 * 					src 			    	--------------------------
		 * 					dst		'lower' ----------------------					'higher' position in memory
		 * So that src is always 'ahead' of dst.
		 * If we went right --> left, the dst in the overlap region would be altered prior to s[i] 'arriving' there and thus
		 * src would be altered, which we don't want.	
		 *
		 * 										abcdef789
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dst);
}
