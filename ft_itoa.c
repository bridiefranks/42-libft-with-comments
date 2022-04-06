/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:40:00 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 14:55:54 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function takes an int (n) and converts it to chars (reverse of atoi). The function countdigits
 * (static, as per subject pdf) works out how many digits there are in the number. Ft_itoa then
 * returns a string of chars (allocated by malloc) representing the integer received. 'Negative 
 * numbers must be handled.'*/ 
#include "libft.h"

static int	countdigits(long int n)
/* this function counts how many digits there are in the int number (given to this function as a long
 * int- so that countdigits is a more versatile function and may be used in other situations with long
 * ints) in order to be able to allocate the right amount of memory for the char string in ft_itoa.*/
{
	unsigned int	count;

	count = 0;
	if (n < 0)
	/*if the number is negative, add one to the count (so that the '-' counts as a digit) and turn 
	 * the number positive by multiplying it by -1. This is so that it can then enter the while loop
	 * and be manipulated as a positive number*/
	{
		count++;
		n *= -1;
	}
	while (n)
	/* while the number is not zero...*/
	{
		count++;
		n /= 10;
		/* add one to count for each time the while loop plays out (which is once per digit) and
		 * divide the number by ten each time. If the number is -6834 for example, dividing by
		 * 10 will produce -683, then again will produce -68, etc. It is a way of isolating 
		 * each digit incrementally.*/ 
	}
	return (count);
	/*return the count (e.g. 5) back to ft_itoa.*/
}

char	*ft_itoa(int n)
/* the 'main' function. Allocates enough memory to hold the number of digits as worked out by 
 * countdigits, then fills them as shown below*/
{
	long int		num;
	int				sign;
	char			*result;
	unsigned int	digits;

	num = n;
	/*as the function countdigits is expecting to receive a long int (gives more scope?), we must
	 * give it a variable of that type. So num, a long int, is set to equal the inputted int n.*/
	sign = 0;
	/*this variable is used to record whether the number is positive or negative*/
	digits = countdigits(num);
	/*using the countdigits function, the number of digits is worked out. A '-' is included as a
	 * digit.*/
	if (num < 0)
	/* if the number is negative*/
	{
		num *= -1;
		sign = -1;
		/*multiply the number by -1 to make it positive, and set sign to = -1 as a record that
		 * the number was negative*/
	}
	result = ft_calloc((digits + 1), sizeof(char));
	/*allocate enough memory to take the number of digits (worked out from countdigits) plus one
	 * for the null, in char memory type. Calloc is used rather than malloc, such that all the 
	 * allocated memory spots are filled with zeros. This means the last position can be left
	 * unchanged, as we want it to be a null terminator anyway. The newly allocated memory is 
	 * pointed to by the char pointer result.*/
	if (!result)
		return (0);
	/* if the memory allocation was unsuccesful and calloc returns a null pointer, ft_itoa returns
	 * null (or zero, same thing)*/
	result[0] = '-';
	/*set the value at the first position in the string to be '-'. The number is next filled in, back
	 * to front; if it was a positive number the '-' at the front will be overwritten with a char,
	 * whereas if the number was negative the '-' will be left at the front (as per the following 
	 * code...*/
	while (digits + sign)
	/* while digits and sign added together are not null. If the number was positive, sign should 
	 * still be 0 and so if the int was 6834 for example, the while loop would continue until (not
	 * including) digits = 0. Whereas if it were -6834, digits + sign = 4 + -1 = 3, so the while 
	 * loop would continue until (not including) digits = 1, and in this way would stop one 
	 * position before the start, thus leaving the '-' at the front intact.*/
	{
		result[digits - 1] = (num % 10 + '0');
		/* sets the value at position (digits - 1) (which is the END of the string, ie we're
		 * working backwards) in the newly allocated string 'result' 
		 * to = the number mod 10 (which gives you the last digit of any number), plus '0' to 
		 * convert the int to a char character using the ascii value. So, using our example of 
		 * num = -6834, num % 10 is 4, plus ascii value of '0' (48) converts it to ascii number
		 * 52 ie the character 4.  
		 * (it is [digits - 1] because an index starts at count 0 whereas the number of digits 
		 * starts at count 1, so digits - 1 is the actual end of the string. The position at
		 * index position 'digits' is where the zero, placed by calloc, is now left to be the
		 * null terminator.)*/
		num /= 10;
		/*then the number is divided by 10 --> our example is now -683. Doing mod 10 on this
		 * new number will isolate the next digit along for us, so we can convert it to char
		 * as per above.*/
		digits--;
		/*iterate backwards through the string, filling in the digits backwards. Until, (or 
		 * actually, just before) we reach either digits = 1 or digits = 0 (depending on pos 
		 * or neg). In our example, of -6834, the while loop will break when 
		 * (digits + sign) = 0. As it is negative, sign is -1, and the value of digit 
		 * (from countdigits) is 5 (including the '-'.) Thus, the while loop will continue 
		 * until digits has reached 1 (as 1 + -1 = 0). Which leaves the first
		 * spot unchanged, and remember this was initially assigned as '-'. (However if the
		 * number was positive, the while loop would continue one extra spot along, as there
		 * is no '-' included in the number of digits and as sign is 0 not -1 in the case of
		 * a positive number,, and overwrite the '-' at the start.) 
		 * It is easiest to understand by writing out all the variable values at each stage of
		 * subsequent while loops are performed, and seeing how the values change.*/
	}
	return (result);
	/* return result, which is a pointer to a string of chars containing the original int number
	 * represented in char type.*/
}
