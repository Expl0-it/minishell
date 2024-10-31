/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:49:19 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:07 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Compare memory areas.
 * 
 * 	The memcmp() function compares the first n bytes
 *	(each interpreted as unsigned char)
 *  of the memory areas s1 and s2.
 * 
 *  @param s1 first memory area to compare
 * 	@param s2 second memory area to compare
 * 	@param n maximal number of bytes to compare
 *  @return integer less than, equal to, or greater than zero
 *  if the first n bytes of s1 is found
 *  respectively, to be less than, to match,
 *  or be greater than the first n bytes of s2
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*p_s1 != *p_s2)
			return (*p_s1 - *p_s2);
		p_s1++;
		p_s2++;
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	char	*a = "abbad";
	char	*b = "abbax";
	int num = ft_memcmp(a, b, 5);
	printf("%d", num);
	return (0);
}
*/
