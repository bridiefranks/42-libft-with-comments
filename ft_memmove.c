/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:19:24 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/22 14:16:53 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function copies len bytes from string src to string dst. This function is used when the 2 strings may overlap (contrast
 * memcpy). The copy is always done in a non-destructive manner
 * A pointer to the original value of dst is returned.
 * I find this function really hard to explain! -the logic in regards to the overlap region and direction
 * of copying. Hopefully it makes a bit of sense and by writing it out or visualising with objects etc it
 * can make more sense...*/
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;
	/* see descriptions in previous functions as to why we do this ^*/

	d = dst;
	s = src;
	if (d < s)
	/*if dst is stored at a 'lower' address than src, and therefore the overlap region is at the
	 * end of dst and the start of src (rather than vice versa) we want to start copying from the
	 * start of src and move upwards. If we started from the end of src and worked backwards, we'd
	 * reach the overlap region last and be copying from a position that has already been altered.
	 * e.g. if the whole memory area is abcdefghijkl and dst is abcdef and src is defghi, if we
	 * started copying from the start of src (good) the result would be: defghighijkl. Whereas if
	 * we started copying from the end of src and worked backwards, it would be: ghighighifkl. 
	 * This is hard to explain sorry, probably best to write it out on paper to visualise...but
	 * essentially, the main point is that we want to copy first from the overlap region, so that
	 * the information there is not lost. If we went in the opposite direction, the data in the
	 * overlap region would be altered from the start and as such the original data in that region
	 * would be lost and not able to be copied.*/
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}/*so continue iterating through, setting the value at the position i in dst to equal the 
		   corresponding value at position i in src, until len is reached.*/
	}
	else
	/*whereas, if dst is stored at a 'higher' address than src, the overlap region is at the end of 
	 * src and the start of dst. In this case we want to copy from the end of src and travel
	 * backwards thorugh src,in order to copy FROM the overlap region first rather than last, when 
	 * would already have been altered. Same reasoning as before, just in reverse.*/ 
	{
		i = len;
		/*so the counter is set to the end of the copied region this time, in order to work
		 * backwards*/
		while (i > 0)
		/*while we haven't yet reached the start of src..
		 * note: it isn't while i >= 0, because we have set i to = len which means it will take 
		 * len + 1 increments to reach i = 0, which is 1 too many. We only want to take len 
		 * increments and so stop at i = 1 not i = 0 */
		{
			d[i - 1] = s[i - 1];
			/*set the value at i-1 in dst to equal the corresponding value at i-1 in src.
			 * Is i - 1 because the index/counter always starts at position 0 whereas the len
			 * value counts starting at 1. For e.g, if len = 6 ie we want to copy 6 bytes, we 
			 * want to copy back starting from i = 5 as the 6th byte is at i = 5 (0,1,2,3,4,5
			 * = 6 bytes) */ 
			i--;
			/* continue copying backwards through src until reaching the beginning of src (ie
			 * when i = 1) */
		}
	}
	return (dst);
	/* return (void) pointer to start of dst*/
}
