/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:40:58 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/11 11:46:27 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Copy memory area. 
 * 
 * 	The memmove() function copies n bytes from memory area src
 * 	to memory area dest.
 * 	The memory areas may overlap: copying takes place as though the bytes in src
 * 	are first copied into a temporary array that does not overlap src or dest,
 *  and the bytes are then copied from the temporary array to dest.
 *
 * 	@param dest memory area to copy to
 * 	@param src memory area to copy from
 * 	@param n maximal number of bytes to copy
 *  @return The memmove() function returns a pointer to dest
 *  memory area copied to)
 */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*p_src;
	char		*p_dest;
	size_t		i;

	if (NULL == src && NULL == dest)
		return (NULL);
	p_src = (const char *)src;
	p_dest = (char *)dest;
	if (p_src < p_dest)
	{
		while (n--)
			p_dest[n] = p_src[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}

/*
#include <stdio.h>
int main(void)
{
	char	*a = "abcde0123456789";
	char	b[16];

	char	*p_b = ft_memmove(b, a, 10);
	printf("%s, %s", b, p_b);
	return 0;
}
*/
