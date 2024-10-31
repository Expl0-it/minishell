/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:49:30 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:21 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Locate character in string.
 * 
 * 	The strchr() function returns a pointer to the 
 *	first occurrence of the character c in the string s.
 * 	The terminating null byte is considered part of the string,
 *  so that if c is specified as '\0', these
 * 	functions return a pointer to the terminator.
 * 
 *  @param s string to scan in
 * 	@param c character to scan for (unsigned char)
 *  @return pointer to the matched character or NULL if not found
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>

int main(void)
{
	char	*a = strchr("abc", 'a + 256');
	char	*b = ft_strchr("abcdb", 'b');
	printf("%s\n%s\n", a, b);
	return (0);
}
*/
