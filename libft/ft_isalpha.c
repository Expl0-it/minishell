/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:45:11 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:01 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Checks for an alphabetic character.
 *
 * 	Check whether c, which must have the value of an unsigned char
 *  falls into a certain character class according to the current locale.
 *
 *  @param c int value of character in character encoding (unsigned char)
 *  @return 1 if true, 0 if false
 */
int	ft_isalpha(int c)
{
	if (('A' <= c
			&& c <= 'Z')
		|| ('a' <= c
			&& c <= 'z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int i = -10;

	while (i <= 530)
	{
		a = ft_isalpha(i);
		printf("%d :%d\n", i, a);
		i++;
	}
	return (0);
}
*/
