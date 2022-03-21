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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)

{
	size_t	dsti;
	size_t	srci;
	size_t	tot_len;

	if (!dstsize)
		return (ft_strlen(src));
	if (dstsize < ft_strlen(dst))
		tot_len = dstsize + ft_strlen(src);
	else
	{
		tot_len = ft_strlen(dst) + ft_strlen(src);
	}
	dsti = ft_strlen(dst);
	srci = 0;
	while (src[srci] && dsti < dstsize - 1)
	{
		dst[dsti] = src[srci];
		dsti++;
		srci++;
	}
	dst[dsti] = '\0';
	return (tot_len);
}
