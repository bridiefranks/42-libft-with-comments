/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:39:17 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/03 18:39:26 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_words(char const *s, char delim)
{
	size_t	i;
	size_t	count;
	char	tru;

	i = 0;
	count = 0;
	tru = 1;
	while (s[i])
	{
		if (tru && s[i] != delim)
		{
			tru = 0;
			count++;
		}
		else if (!tru && s[i] == delim)
			tru = 1;
		i++;
	}
	return (count);
}

static char	*fillstring(char const**ss, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while (**ss && **ss == c)
		(*ss)++;
	while ((*ss)[i] && (*ss)[i] != c)
		i++;
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, *ss, i);
	*ss += i;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	unsigned int	count;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	count = num_words(s, c);
	strings = ft_calloc(count + 1, sizeof(char *));
	if (!strings)
		return (strings);
	while (i < count)
	{
		strings[i] = fillstring(&s, c);
		if (!strings[i])
			return (NULL);
		i++;
	}
	strings[i] = NULL;
	return (strings);
}
