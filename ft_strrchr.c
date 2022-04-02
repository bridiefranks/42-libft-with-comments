/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:26:18 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 10:44:02 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* same concept as strchr, except the function returns a pointer to the last rather than the first 
 * occurence of the character c in the string pointed to by s*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	/* set i to be at the end of the string */
	while (i >= 0)
	/* while we haven't yet reached the beginning of the string...*/
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i--;
		/*same concept as in strchr, just working backwards not forwards.*/
	}
	return (NULL);
}
