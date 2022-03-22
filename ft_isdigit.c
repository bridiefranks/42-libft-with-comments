/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:35:57 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/22 12:27:10 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Similar to isalpha, this function tells you whether the int c you input is a digit character (return 1) 
 * or not (return (0).
 *Could also be written as: if ((c >= 48) && (c <= 57)).*/
#include "libft.h"
/*#include <stdio.h>*/

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
	{
		return (1);
	}
	return (0);
}

/*int	main(void)
{
	int	v;

	v = ft_isdigit('f');
	printf("%d\n", v);
	return (0);
}*/
