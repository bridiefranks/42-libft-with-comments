/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:49:10 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/10 18:35:54 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* again, see ft_putchar_fd for more details regarding fd. Otherwise, this is like the ft_putnbr we saw
 * in the piscine: the function takes a number and writes it as a char, using ft_putchar. We can't write
 * numbers of 2 or more digits, so for those numbers we have to break them down into their individual 
 * digits in order to write them. Nothing is returned as it is a void function. */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	/* for the special case where n is this (very large) negative number, we will just call on 
	 * ft_putstr_fd to write the string below. This is a bit of an outlier case, that won't work
	 * using the code that follows, as it is the largest negative number, with no positive 
	 * counterpart. ie '2147483648' isn't recognised as an int. This is because ints are described
	 * using a set of 4 bytes, with each bye containing 8 binary bits. Using these bits, there are
	 * enough combinations to make ints from -1 through to -2147483648 and 1 through to 2147483648.
	 * However, because there is also zero to add in there, we can only make up to 2147483647 (ie 
	 * one less than the equivalent max negative number). Hence, we have the code to account for 
	 * this special case, as this particular negative number can't be converted to a positive.*/ 
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	/* otherwise, for all other negative numbers...*/
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
		/*use the function ft_putchar_fd to first write the '-' sign, then use ft_putnbr_fd to
		 * write the actual number (but '-n' so it is converted to a positive number.
		 * This is recursion: calling a function within the same function. If the number were
		 * say -7693, it will write the '-' then call the function again but with 769 instead.
		 * In that case, the number 7693 no longer qualifies for this if statement, and will 
		 * cause the next one to be true instead...*/ 
	}
	else if (n > 9)
	/* if the number was positive originally, and 2 or more digits, or if the number was negative
	 * and has now been converted to positive (and was 2 or more digits)...*/
	{	
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10 + 48), fd);
		/* recursively call on the ft_putnbr_fd function, but dividing by 10 each time to chop 
		 * off the last digit each time (so using our example, n is now 7693, then each time the
		 * function is called becomes 769, then 76, then 7...but now it is 7, this if statement
		 * is not true (as 7 < 9) so instead the final else statment is entered and 7 is written
		 * using ft_putchar_fd.) However, each time the function is called recursively, the code
		 * doesn't complete and enters the stack half completed. So for our example, 7693 is 
		 * the original number, which is then divided by 10 and called by ft_putnbr_fd again.
		 * However, there's still the next line in code 'to go' for 7693: the ft_putchar_fd of 
		 * mod 10 + 48 bit. 7693 is added to the stack first, then 769, then 76 (as these also
		 * all are 'unfinished' having not completed the following line either). Then the stack
		 * is 'unpacked' in reverse order, with 76 coming off first (as it is on the top) and
		 * continuing through its unfinished code: ie ft_putchar_fd((n % 10 + 48), fd) line is
		 * carried out for 76. This line writes the char of the number (76) mod 10 (which is
		 * 6) + 48 which is the ascii value of 0 (adding 48 to it converts the int to char. See
		 * ft_itoa for reasoning.) So, the number 6 is written. Remember that the first digit
		 * 7 has already been written from the else statement below, and the '-' has already 
		 * been written from the if statement above. Thus, so far we have written '-76'. Next,
		 * 769 comes off the stack, and goes through the ft_putchar_fd((n % 10 + 48), fd) line
		 * as well, resulting with the 9 being written as a char. Now we have '-769'. Finally,
		 * 7693 comes off the stack and the same process occurs with the full '-7693' being 
		 * written. All unfinished code is now complete and we have our result. Note that my 
		 * way of explaining is fairly colloquial and perhaps isn't the most technically 
		 * accurate, but might help in understanding/conceptualising!*/ 
	}
	else
	{
		ft_putchar_fd(n + 48, fd);
		/*so this bit either writes the first digit of a multi-digit number, or if the number was
		 * only ever 1 digit long, writes the one and only digit.*/
	}
}
