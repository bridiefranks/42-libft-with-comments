/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfranks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:39:17 by bfranks           #+#    #+#             */
/*   Updated: 2022/03/03 18:39:26 by bfranks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* this function takes a string (s), consisting of series of chars separated by specific characters
 * called delimiters (delim), and splits it at the delimiters to produce an array of new strings. 
 * For example, if the delim character is '-', and the original s string is: three-fat-grass-hoppers,
 * ft_split will create an array of pointers, each pointing to the strings: three, fat, grass and 
 * hoppers. This is a 2D array- what is returned is a pointer to an array of pointers (that each point
 * to their own string). Also, the pointer array must end with a null pointer.
 * The flow of the code works as follows. Ft_split passes the function num_words the string s and the
 * delimeter c. Num_words then works out how many words are within the string (in our example, 4).
 * Ft_split then allocates enough memory to take the POINTERS (4) that will point to these strings (not
 * the strings themselves), plus 1 for the null pointer at the end. As calloc rather than malloc is
 * used, the allocated spaces for the pointers are filled with zeros (not really sure why this is
 * needed though- why malloc isn't used. I suppose either is fine. In fillstring, calloc is used to fill
 * the memory with zeros so that the last zero is left unchanged and therefore becomes the null
 * terminator. Not sure if this works with a zero becoming a null pointer though). It'll then use the 
 * function fillstring to fill each allocated memory spot with a pointer that points to one of the 
 * strings/words each, that have been split (three, fat etc). The tricky thing with this code is getting
 * the function fillstring to 'remember' or 'retain' which word it is up to in s, even after each 
 * individual function call has finished. This is achieved by using a double pointer **s; a pointer
 * to a pointer. This means we can move the pointer that the double pointer is pointing to (*ss)
 * along the string s: not just incrementing an index, but actually moving the pointer. But this
 * pointer is still pointed to by the double pointer (which hasn't moved or anything) and is also 
 * referred to within the main function ft_split. So, as this variable (the double pointer) is referred
 * to in both functions, even after each function call of fillstring is complete, **ss is not reset
 * as it is still being used in ft_split. Therefore, the position where the single pointer *s was up
 * to is still 'remembered' and can be built upon in the next call of fillstring, when the next word
 * along is copied.
 * So, fillstring produces a pointer to the word it is up to (e.g. 'fat') which has been allocated 
 * space and copied from the original s string into that allocated space. This is then passed back to
 * ft_split, which sets the value at position i in strings (which is an array of pointers, remember) to
 * be the pointer to the word we have produced in fillstring. In this way, the array of pointers 
 * (strings) is iterated through and set to equal the pointers to each individual word as produced by
 * fillstring. Finally, once the array is full and there is a pointer to each word from the original
 * string, we set the last spot in the pointer array to null (ie make it a null pointer) and return 
 * the double pointer, strings, which points to the array we have made, filled with pointers each 
 * pointing to their own string, containing one word split from the original string s.*/
#include "libft.h"

static size_t	num_words(char const *s, char delim)
/*this function is first on the page, but read ft_split first.
 * This function takes (passed from split) the original string to be split (s) and the char variable 
 * delim, which contains the character we are designating as the delimeter: in our example, '-' (where
 * our example is: three-fat-grass-hoppers). Using these, it counts how many words there are, 
 * separated by the delim character. It does this by repeatedly modifying the value of 'tru' in order 
 * to determine the position in the string, by using two different if statements. Tru will be 0 while 
 * iterating past non-delim characters, then as a delim character is met it will meet the requirements
 * of the appropriate if statement, resetting the tru value back to 1. Each time tru is reset to 0,
 * which happens at every non-delim character that immediately follows a delim character (but not a 
 * delim character itself), count goes up by one. This count is returned, and used in ft_split as the
 * total number of words in the string s. This method is used, rather than just counting how many
 * delim characters there are and using that number (plus one) as the word count, for two reasons:
 * 1. there may be two or more delim characters in a row: '----' and we wouldn't want to interpret
 * that as the presence of 4 words. And 2. there may or may not be a delim character at the end/s of
 * the string, which would alter the interpreted amount of words if the delim were used as the word 
 * counter. As such, we want to count the actual words not the gaps between them. */
{
	size_t	i;
	size_t	count;
	char	tru;

	i = 0;
	count = 0;
	tru = 1;
	/*tru is set to 1 originally, so that upon the first encounter of a non-delim character, the
	 * first if statement will be met and the count will be increased to 1 (representing the count
	 * of the first word)*/
	while (s[i])
	/* while we haven't yet reached the null terminator of original string s...
	 * Initially, if there are delim characters at the start of the string, neither of the if
	 * statements' conditions will be met and as such we will iterate through the string (i++)
	 * until a non-delim character is found*/
	{
		if (tru && s[i] != delim)
		/* this if statement is entered if tru = 1 (rather than 0) and if the character at 
		 * position i, that we're looking at, is not a delimeter. So in our example, the char 
		 * 't' of 'three' will cause this if statement to be true, for tru to then be reset to 0 
		 * and for count to be set to one. Once this has happened, the next if statement is not
		 * true (as 't' isn't == delim char) so i is incremeneted. Now position i is at the 'h'
		 * in 'three'. True is now false, so the first if statement is not met, but the char
		 * is not the delim either, so the second if statement is not met either. Thus, i 
		 * continues to be iterated until a delim character is reached, in which case we enter
		 * the second if statement...*/ 
		{
			tru = 0;
			count++;
		}
		else if (!tru && s[i] == delim)
		/*when a delim character is encountered (and tru is 0 not 1), tru is reset to 1, such that
		 * we are now able to fulfill the first if statement conditions again, once we reach the
		 * first non-delim character of the next word. When this happens, count is once again
		 * incremented, as we have now reached the second word. But again, after this, tru is
		 * reset to 0 and neither if statement is true until we reach another delim character.*/
			tru = 1;
		i++;
		/*continue with this pattern until the whole string is iterated through, and all the 
		 * words counted, and we have reached the null terminator and hence break out of the
		 * while loop.*/
	}
	return (count);
	/* the total count is returned (in our example, 4, for 4 words) and given back to ft_split.*/
}

static char	*fillstring(char const**ss, char c)
/* this function takes a double pointer from ft_split (passed as &s) and the delim char c. It returns 
 * a char pointer str back to ft_split, to then be used in the array of pointers we are ultimately 
 * making.
 * (Note it is a static char function as described in the project pdf).*/
{
	char	*str;
	size_t	i;

	i = 0;
	while (**ss && **ss == c)
	/* while the double dereferenced double pointer (ie, the actual char value in the string, say
	 * 't' or 'h' or '-') is not null (so we haven't reached the end of the original string s) and
	 * while the double dereference value IS equal to '-'...*/
		(*ss)++;
		/* increment the POINTER ss along one spot. If there are multiple delims/'-' in a row,
		 * this while loop will continue iterating the pointer along until the pointer is
		 * pointing at the first character of a word (not a delim) and hence the while loop is 
		 * broken. This is an important thing to understand- the ('single') pointer itself (*s) is
		 * actually moving along the string. We are not iterating a counter. We are iterating a
		 * pointer. But the double pointer **ss is still pointing at the 'single' pointer, and
		 * as it is referred to in the main ft_split function as well, the value of it isn't lost
		 * once each function call of fillstring is finished. In this way, the position of *s in
		 * the string s is retained each time, and so we can continue to work through the string
		 * from where we got to last time rather than start at the beginning each time.*/
	while ((*ss)[i] && (*ss)[i] != c)
	/*while the double dereferenced value of ss at position i (this is sort of another way of
	 * writing **ss, just that writing it this way (*ss[i]) means we can then use a counter i to
	 * iterate) is not null (so we haven't reached the end of the original s string) and while the
	 * value is not the delim/'-'...*/
		i++;
	/*iterate i. So once the while loop has broken, that is, once we have reached a delim character
	 * of the end of the string, we know that we have reached the end of a word. We are now in a 
	 * situation where the pointer *s has been positioned at the start of this current word, and 
	 * the counter i is now positioned at the end of the current word (actually at the first 
	 * character after the end of the word- either a delim, or null). Next we want to allocate
	 * enough memory to contain the number of chars in that word, which is equal to i ((as i is
	 * reset to zero each time the function is called, and its '0' position is therefore at the start 
	 * of the word, where *s is now pointing)) plus one spot for the null terminator. I actually 
	 * think that this allocates one too many spots as i is already positioned off the end of the
	 * word? So we'd want i not i + 1 spots allocated. I believe. Anyway, we use calloc 
	 * rather than malloc, so we don't have to manually set the last position to null (as calloc 
	 * fills with zeros, and the last position will be left unchanged, ie 0/null).*/  
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	/* if the memory allocation was unsuccessful; if the heap was full, ft_calloc returns a null 
	 * pointer and fillstring therefore returns null.*/
	ft_memcpy(str, *ss, i);
	/* now memcpy is called, to copy the contents of the string pointed to by *ss to the newly 
	 * allocated memory space pointed to by str, up until the point i (refer back to this function
	 * to see how the two work together). This is the actual filling of the new string bit.*/
	*ss += i;
	/*then, the (single) pointer *ss is set to equal itself plus i, effectively moving it to now 
	 * point at the delim character preceeding the next word along, in preparation for the next 
	 * time the function is called, when we want to copy the next word in the string.*/
	return (str);
	/*and we return the pointer str to ft_split, which points to the newly made string containing
	 * a single word.*/
}

char	**ft_split(char const *s, char c)
/*this is the 'main' or 'central' function. It receives a pointer to the string s that we are splitting,
 * plus the delimiter value c that we are splitting the string by. It Returns a pointer to an array of
 * pointers, each pointing to its own string containing one word of the original s string (defined as 
 * having a delim character on either side).*/
{
	char			**strings;
	unsigned int	count;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	/*if the string is empty, just return null!*/
	count = num_words(s, c);
	/*count is the number of words. This is worked out using the function num_words (see top of page).
	 * We give num_words the string, and the delimeter to look for */
	strings = ft_calloc(count + 1, sizeof(char *));
	/*we use ft_calloc to allocate enough memory to hold the array of POINTERS (not chars as done 
	 * previously!) which each point to strings themselves. The number of pointers requiring memory
	 * space is equal to the number of words as determined by num_words. Plus, an extra spot for the
	 * null pointer at the end. The sizeof type is char pointer, rather than char, as of course we
	 * are filling the allocated memory with char pointers not chars. I'm not sure why calloc is 
	 * used rather than malloc, I assume either is fine? Strings, a double pointer, is set to point
	 * at this newly allocated memory which will be shortly filled with pointers.*/
	if (!strings)
		return (strings);
	/*if the memory allocation was unsuccessful: if the heap was full, and a null pointer
	 * is returned (ie 'strings' is null), ft_split returns strings, which is this null pointer. 
	 * Could also have written 'return (NULL)' (same thing).*/
	while (i < count)
	/* i iterates through the array of pointers, 'strings', up until the position count is reached.
	 * This is the number of words in the string, so we only want as many pointers as there are
	 * words. (It isn't while (i <= count) because index i starts at value zero whereas count starts
	 * at value 1).*/
	{
		strings[i] = fillstring(&s, c);
		/*set the allocated memory at position i within the array of pointers to be equal to the
		 * pointer returned from fillstring. Then increment i, such that each pointer position
		 * is now filled with a pointer that points to an individual word. Fillstring is passed
		 * a double pointer: because s is a single pointer, the address of s is therefore a 
		 * double pointer, as the vlaue of a pointer is the address of the thing it's pointing 
		 * at. So therefore the address of a pointer is in fact a double pointer. (Note this 
		 * double pointer is then received into fillstring as ss- the name doesn't matter 
		 * between functions).*/
		if (!strings[i])
			return (NULL);
		/*if fillstring returns a null pointer (see fillstring) we want ft_split to then return
		 * null. So this bit of code is saying that if the value at position i in strings is set
		 * to null according to fillstring, we want ft_split to then return null too.*/
		i++;
		/* iterate through the array of pointers...*/
	}
	strings[i] = NULL;
	/*finally, set the final spot in the array of pointers (after the final word's pointer has been
	 * added in) to be a null pointer, as specified in the man*/
	return (strings);
	/* and return the double pointer strings, which points to the array of pointers which each point
	 * to their own individual word split from the original string s.*/
}
