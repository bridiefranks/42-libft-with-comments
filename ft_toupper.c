/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:23:34 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/10 12:16:59 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function converts any lowercase character (passed as an int) into an upper case character, and 
 * then returns that character*/
#include "libft.h"
/*#include <stdio.h>*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	/* if int c is between the ascii values corresponding to the lowercase a and z...*/
	{
		c = c - 32;
		/* change the value of c to be 32 ascii characters less than the original, which equates to
		 * the upper case version of the original lowercase letter*/
	}
	return (c);
}
/*
int	main(void)
{
	int	b;
	b = ft_toupper('8');
	printf("%d\n", b);
	return (0);
}*/
