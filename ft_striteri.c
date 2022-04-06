/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:42:10 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 15:27:21 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*this function doesn't really 'do much', it just demonstrates how a function can be passed as an
 * argument in the prototype.
 * The function takes a string, iterates through it, and applies the function f to each character 
 * within that string. We don't know what the function f actually does; it is not described here. But
 * it could represent any number of possible functions that may be applied. The difference between this
 * function and ft_strmapi is that this function takes a string and applies the function f to each of its
 * chars. Whereas strmapi takes a string and makes a new string consisting of the chars from the old 
 * string, but having had the function f applied to them. */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
/* in this prototype, we are given a char pointer to a string s (as we have seen many times) but also
 * a void pointer to the function f, to which we pass an unsigned int (the index position i) and a char
 * pointer (the address of the character in question). Nothing is returned, as it is a void function.*/
{
	unsigned int	i;

	if (s)
	/* if the string s is not empty...*/
	{
		i = 0;
		while (s[i])
		/* while we haven't yet reached the end of string s...*/
		{
			f(i, s + i);
			i++;
			/* pass the index position i, and the address of the character at that position
			 * (s + i) to the function to be (potentially) altered by the function f, then 
			 * continue iterating through string s. (The address of the character is (s + i)
			 * because the value of a pointer is the address of the thing it's pointing to.
			 * The pointer s points to the start of the string, and has the value of the 
			 * address of the start of the string. Therefore the pointer (s + i)
			 * points to the spot that is i spots away from the start of the string s, and
			 * thus has the value of the address that is i spots away from s. In this way,
			 * we are passing the character by its address, to f (as described in the function
			 * description).*/
		}
	}
}
