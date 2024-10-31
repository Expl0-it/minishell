/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:20:40 by mmichali          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:40 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Compare two strings.
 * 
 * 	Compares the two strings s1 and s2. It returns an integer
 *  less than, equal to, or greater than zero if s1 is found,
 *  respectively, to be less than, to match, or be greater than s2.
 *  It only compares the first (at most) n bytes of s1 and s2.
 * 
 * 	@param s1 first string to compare
 * 	@param s2 second string to compare
 * 	@param n maximum number of bytes to compare
 *  @return integer less than, equal to, or greater than zero 
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && (s1[i] == s2[i]))
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[20] = "123456789";
	char s2[20] = "123456789";
	int a = ft_strncmp(s1, s2, 0);
	int b = strncmp(s1, s2, 0);
	printf("%d, %d", a, b);
	return 0;
}
*/
