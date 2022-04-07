/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:32:27 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/17 13:29:12 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function converts (number) characters to ints. It will iterate through a given string; if the
 * characters are a space or between the ascii values of 9 and 13 (includes things like tabs) it will keep
 * iterating and checking until it finds number characters (by using ft_isdigit to see if they're numbers). 
 * Then, it will convert those number characters to int type. If the characters in the string stop being 
 * digits (e.g. become letters or spaces etc) it will stop checking and return the resultant number, in 
 * int form. So it will only convert the first uninterrupted group of digits and none after that.*/ 
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	neg;
	int	i;

	result = 0;
	neg = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	/* while the value at position i in the string is a space, or between ascii values 9 and 13 (horizontal
	 * tab, new line etc) it will continue iterating through the string. (Not entirely sure why its 9-13
	 * specifically but I assume it's in a function description somewhere)*/
		i++;
	if (str[i] == '-' || str[i] == '+')
	/* if the value is a negative sign, ie the number is negative, set 'neg' variable to equal 1 and move to
	 * the next character in the string. Later on, if neg was set to 1, this will be used to make the final
	 * int number negative again.
	 * If the character is +, just iterate to the next character in the string.*/
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (ft_isdigit(str[i]))
	/* now that we've passed any spaces or tabs or -/+ signs etc, if we have come across a digit, we want to
	 * convert it and any following digits to int type. How do we know if the character is a digit? By using
	 * ft_isdigit. If it is true, it is a digit. However if the character is not a digit or any of the 
	 * previouis options (space, tab etc) and is instead say a letter, it will not enter the while loop
	 * and will instead just return result, which is at the start set to zero.*/
	{
		result = result * 10 + (str[i] - '0');
		i++;
		/* if it is a digit though, it will set result to equal result multiplied by ten (initially
		 * zero as result starts at zero) plus the value at that position minus the ascii value of 0.
		 * This subtraction of ascii value of zero (which is 48) converts the char digit into the int
		 * value of that digit. For example, if the char digit was 8 (56 on ascii), by subtracting the
		 * ascii value of 0 (48 on ascii) the result of 56 - 48 is now the int 8. Note it only works
		 * digit by digit, rather than the whole 'number' at once.
		 * Then it will increment to the next digit- or, if the next character in the string is no 
		 * longer a digit, it will stop there.
		 * So for an example, if the string was '     1867aaaaaa', the code would initially iterate 
		 * through all the spaces, reach 1 and recognise it as a digit via ft_isdigit, set result to equal
		 * 0 *10 + ascii of 1 - ascii of 0. So result now equals 1 in int form. Then, it will increment
		 * i, and move to the next position, which contains 8. It is a digit. Result is now 1 from the
		 * previous digit; now result will be reset to 1 * 10 + (ascii of 8) - (ascii of 0) and thus
		 * equal 18 in int form. Again, will increment to the next position which contains 6. Result 
		 * is now 18, and will be reset again to 18 * 10 + (ascii 6) - (ascii 0) ie = 186. One last 
		 * increment of i will then make result = 1867- the original number, but now in int form not
		 * char! As i increments after the 7 digit, the a value after it is no longer a digit and thus
		 * the while loop is broken.*/
	}
	if (neg)
		return (-result);
	/*if the neg variable is true, ie it is not zero, (which would be the case if it were originally a neg 
	 * number and therefore neg was set to 1) we return the result with a negative sign in front of it*/
	return (result);
	/*otherwise, if the neg variable wasn't changed, we just return the value of result (the number now in
	 * int type*/
}
