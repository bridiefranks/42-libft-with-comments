/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:33:16 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 13:37:36 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function is like malloc in that it allocates memory, but it also then fills the allocated memory
 * with zeros by using ft_bzero. It returns a pointer to the start of the allocated region.*/
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		length;

	length = size * count;
	/* the length of the memory we want to allocate is the size of the type (e.g. 1 for chars which
	 * are 1 byte long, vs 4 bytes for ints etc) multiplied by how many of them we want. For example
	 * a string "dfkjen" we would want to allocate 1 * 6 = 6 bytes of memory.*/
	ptr = malloc(length);
	/*input this length into malloc, and set a pointer 'ptr' to point at the start of it*/
	if (!ptr)
		return (NULL);
	/* if the memory allocation failed, e.g. if the heap did not have room, the resultant pointer will
	 * be a null pointer and thus null will be returned.*/
	ft_bzero(ptr, length);
	/* this now fills the allocated memory with zeros (up to length bytes, but this is the whole of the
	 * allocated memory anyway)*/
	return (ptr);
	/*and returns a pointer to the new string of zeros freshly allocated.*/
}
