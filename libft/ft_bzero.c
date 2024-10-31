/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:37:35 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:58:55 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Write zero-valued bytes.
 *
 *  The bzero() function sets the first n bytes of the
 * 	area starting at s to zero (bytes containing aq\0aq).
 *
 *  @param s pointer to a starting memory
 * 	@param n number of bytes to write to
 *  @return Void
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
int main()
{
	char str[50] = "iwejfiweoiwe wefwjiofewio wiefj";
	printf("\nBefore bzero(): %s\n", str);

	// Fill 10 characters starting from str[10] with '.'
	ft_bzero(str + 10, '.', 10*sizeof(char));

	printf("After bzero():  %s", str);
	return 0;
}
*/
