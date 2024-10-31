/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:39:05 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:23 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Apply function to evry character
 *
 * Applies the function ’f’ on each character of
 * the string passed as argument, passing its index
 * as first argument. Each character is passed by
 * address to ’f’ to be modified if necessary.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	if (s && f)
	{
		while (s[index])
		{
			f(index, &s[index]);
			index++;
		}
	}
}

/*
TODO

#include <stdio.h>
int main(void)
{
	char	*str = "42";
	ft_striter(str, f);
	return 0;
}
*/
