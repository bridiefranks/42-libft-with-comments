/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:13:21 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/22 12:31:03 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*isalpha() tells you if what you input in the main is in the alphabet (return 1) or not (return 0).
 *We compare the int c of interest against the ascii character of 'A' and 'Z'; alternatively, it could
 be written as: if (c <= 90 && c >= 65)... where 90 is the ascii value of 'Z'.*/
#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
	{
		return (1);
	}
	return (0);
}

int	main(void)
{
	int	a;

	a = ft_isalpha('h');
	printf("%d\n", a);
	return (0);
}
