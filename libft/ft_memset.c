/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:48:36 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:12 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Fill memory with a constant byte.
 * 
 * The memset() function fills the first n bytes of the memory area
 * pointed to by s with the constant byte c.
 *
 * 	@param s pointer to a memory area to fill
 * 	@param c character to fill the memory area with
 * 	@param n number of bytes to fill
 *  @return The memset() function returns a pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>
int main()
{
    char str[50] = "iwejfiweoiwe wefwjiofewio wiefj";
    printf("\nBefore memset(): %s\n", str);
  
    // Fill 10 characters starting from str[10] with '.'
    ft_memset(str + 10, '.', 10*sizeof(char));
  
    printf("After memset():  %s", str);
    return 0;
}
*/
