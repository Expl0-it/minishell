/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:42:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:25 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Concatanate strings.
 * 
 * 	Creates (with malloc(3)) and returns a “fresh” allocated
 * 	string ending with ’\0’,
 *  result of the concatenation of s1 and s2. If the allocation fails
 *  the function returns NULL.
 *
 *  @param s1 the prefix string
 * 	@param s2 the suffix string
 *  @return The allocated string result of the concatenation of the 2 strings
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*new;

	i = 0;
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	while (*s1)
	{
		new[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		new[i] = *s2;
		s2++;
		i++;
	}
	new[i] = 0;
	return (new);
}

/*
#include <stdio.h>
int main(void)
{
	char	*a = ft_strjoin("abc", "def");
	printf("%s", a);
	return (0);
}
*/
