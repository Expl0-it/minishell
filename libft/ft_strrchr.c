/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:39:57 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:44 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Locate character in reversed string.
 * 
 * 	Returns a pointer to the last
 *  occurrence of the character c in the string s.
 * 	The terminating null byte is considered part of the string,
 *  so that if c is specified as '\0', these
 * 	functions return a pointer to the terminator.
 * 
 *  @param s string to scan in
 * 	@param c character to scan for (unsigned char)
 *  @return pointer to the matched character or NULL if not found
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	s += i;
	while (i >= 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s--;
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main(void)
{
	char	*a = strrchr("abcdb", 'b');
	char	*b = ft_strrchr("abcdb", 'b');
	printf("%s\n%s\n", a, b);
	return (0);
}
*/
