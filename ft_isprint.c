/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:06:11 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/22 12:50:04 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function tests whether the inputted int c is a printable character (return 1) or not (return 0).
 * See decimal ascii set numbers 32 - 126 for the list of printable characters.*/
#include "libft.h"
/*#include <stdio.h>*/

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
	{
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	int t;

	t = ft_isprint('7');
	printf("%d\n", t);
	return (0);	
}*/
