/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:48:48 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:50:29 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Scan memory for a character.
 * 
 * 	The memchr() function scans the initial n bytes of the memory area
 *  pointed to by s for the first instance
 * 	of c. Both c and the bytes of the memory area pointed
 *  to by s are interpreted as unsigned char.
 * 
 *  @param s pointer to a memory area to scan in
 * 	@param c value to scan for (unsigned char)
 * 	@param n maximal number of bytes to scan
 *  @return a pointer to the matching byte or NULL if the character not found 
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	size_t			i;

	p_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*p_s == (unsigned char)c)
			return (p_s);
		i++;
		p_s++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*a = "abcd\0w";
	char	*b = (char *)ft_memchr(a, 'w', 6);
	printf("%s", b);
	return (0);
}
*/
