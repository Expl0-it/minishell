/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:41:09 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:29 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Size-bounded string concatenation.
 * 
 * 	The strlcat() function appends the NUL-terminated string src
 *  to the end of dst. It will append at most
 *  size - strlen(dst) - 1 bytes, NUL-terminating the result.
 *
 *  @param dst the prefix string
 * 	@param src the suffix string
 * 	@param size the (maximal numer of bytes - 1) to copy from src to dst
 *  @return the initial length of dst plus the length of src
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	while ((i + j + 1) < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
		dst[i + j] = 0;
	return (i + ft_strlen(src));
}

/*
#include <stdio.h>
int main(void)
{
	char	a[10] = "abc";
	int num = ft_strlcat(a, "def", 2);
	printf("%d, %s", num, a);
	return (0);
}
*/
