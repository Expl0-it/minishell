/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:39:41 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:46 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Trim start and end of a string.
 * 
 * 	Allocates (with malloc(3)) and returns a copy of
 * 	’s1’ with the characters specified in ’set’ removed
 * 	from the beginning and the end of the string.
 * 
 * 	@param s1 string to be trimmed
 * 	@param set reference set of characters to trim
 *  @return The trimmed string or NULL if the allocation fails
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	return (ft_substr(s1, 0, len + 1));
}

/*
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	trimmed = NULL;
	if (s1)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
			end--;
		trimmed = (char *)malloc(end - start + 1);
		if (trimmed == NULL)
			return (NULL);
		ft_strlcpy(trimmed, &s1[start], end - start + 1);
	}
	return (trimmed);
}
*/

/*
#include <stdio.h>
int	main(void)
{
	char	*a = ft_strtrim("   \t  abc      ", "\t c");
	printf("%s", a);
	return (0);
}
*/
