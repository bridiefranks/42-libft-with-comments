/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:47:48 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/22 12:38:41 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*This function tests whether the inputted int c is either a digit or in the alphabet. It returns
 * (1) if this is the case, and returns (0) if c is neither a digit or in the alphabet (e.g. '&' or ^')
 * Here I have used the ascii values rather than the characters as in ft_isalpha and ft_isdigit. Either works,
 * this just saves on line length. A better way would be to just use ft_isalpha and ft_isdigit instead.
#include <stdio.h>*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	int	v;

	v = ft_isalnum('K');
	printf("%d\n", v);
	return (0);
}*/
