/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:24:20 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/10 15:58:13 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* see 'ft_toupper.c' as it is the same but reverse*/
#include "libft.h"
/*#include <stdio.h>*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}	
	return (c);
}
/*
int	main(void)
{
	int	b;
	b = ft_tolower('t');
	printf("%d\n", b);
	return (0);
}*/
