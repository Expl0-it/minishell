/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:45:46 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/11 11:23:11 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Checks for a digit (0 through 9).
 *
 * 	Check whether c, which must have the value of an unsigned char
 *  falls into a certain character class according to the current locale.
 *
 *  @param c int value of character in character encoding (unsigned char)
 *  @return 1 if true, 0 if false
 */
int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a = ft_isdigit('0');
	printf("%d", a);
	return (0);
}
*/
