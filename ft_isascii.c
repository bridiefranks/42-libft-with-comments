/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:01:41 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/22 12:41:04 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function tests whether the inputted int c is an ascii character or not, i.e. between 
 * 0 and 127 on the decimal ascii set. Same logic as isalpha etc.*/
#include "libft.h"
/*#include <stdio.h>*/

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	int	f;
	
	f = ft_isascii('t');
	printf("%d\n", f);
	return (0);
}*/
