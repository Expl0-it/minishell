/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:45:30 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:31 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Size-bounded string copying.
 * 
 * 	The strlcpy() function copies up to size - 1 characters
 *  from the NUL-terminated string src to dst, NUL-terminating the result.
 *
 *  @param dst the prefix string
 * 	@param src the suffix string
 * 	@param size the (maximal numer of bytes - 1) to copy from src to dst
 *  @return the length of src
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;

	length = 0;
	if (size == 0)
	{
		while (src[length])
			length++;
		return (length);
	}
	while (length < size - 1 && src[length] != '\0')
	{
		dst[length] = src[length];
		length++;
	}
	if (length < size)
		dst[length] = '\0';
	while (src[length] != '\0')
		length++;
	return (length);
}

/*
#include <stdio.h>
int main(void)
{
	char	str[10];
	size_t a = ft_strlcpy(str, "abcdfqewfef", 5);
	printf("%d, %s", a, str);
	return (0);
}
*/
