/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:41:54 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:58:53 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Convert letter to upper case.
 * 
 * 	Converts the letter c to upper case, if possible.
 * 	If c is not an unsigned char value, or EOF,
 *  the behavior of these functions is undefined.
 * 
 * 	@param c letter to convert
 *  @return converted letter, or c if the conversion was not possible
 */
int	ft_toupper(int c)
{
	if ('a' <= (unsigned char)c && (unsigned char)c <= 'z')
		c -= 32;
	return (c);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a = ft_toupper('a');
	printf("%c", a);
	return (0);
}
*/
