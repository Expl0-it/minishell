/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:40:10 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:58:59 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Checks for an alphanumeric character;
 *  it is equivalent to (isalpha(c) || isdigit(c)). \n \n
 *
 * 	Check whether c, which must have the value of an unsigned char
 *  falls into a certain character class according to the current locale.
 *
 *  @param c int value of character in character encoding (unsigned char)
 *  @return 1 if true, 0 if false
 */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a = ft_isalnum('0');
	printf("%d", a);
	return (0);
}
*/
