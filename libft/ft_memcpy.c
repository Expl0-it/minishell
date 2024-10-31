/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:47:33 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/11 11:43:41 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Copy memory area. 
 * 
 * The memcpy() function copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap.
 *
 * 	@param dest memory area to copy to
 * 	@param src memory area to copy from
 * 	@param n maximal number of bytes to copy
 *  @return The memcpy() function returns a pointer to dest
 *  memory area copied to)
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;

	if (NULL == src && NULL == dest)
		return (NULL);
	p_dest = (char *)dest;
	p_src = (const char *)src;
	while (n > 0)
	{
		p_dest[n - 1] = p_src[n - 1];
		n--;
	}
	return (dest);
}

/*
#include <stdio.h>
int main(void)
{
	char	*a = "abcdefg";
	char	b[10];
	char	*p_b = ft_memcpy(b, a, 8);
	printf("%p, %s", p_b, b);
	return 0;
}
*/
