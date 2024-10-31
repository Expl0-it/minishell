/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:50:05 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:49:50 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static unsigned int	ft_num_length(int n);

/** @brief Convert integer to string.
 * 
 * 	Allocates (with malloc(3)) and returns a string
 * 	representing the integer received as an argument.
 * 	Negative numbers must be handled
 * 
 * 	@param n the integer to convert
 *  @return The string representing the integer or NULL if the allocation fails
 */
char	*ft_itoa(int n)
{
	char			*string_num;
	unsigned int	length;
	unsigned int	number;

	length = ft_num_length(n);
	string_num = (char *)malloc(length + 1);
	if (string_num == NULL)
		return (NULL);
	ft_bzero(string_num, length + 1);
	if (n < 0)
		number = (unsigned int)-n;
	else
		number = (unsigned int)n;
	if (number == 0)
		string_num [0] = '0';
	while (number != 0)
	{
		string_num[length - 1] = (number % 10) + '0';
		number /= 10;
		length--;
	}
	if (n < 0)
		string_num[0] = '-';
	return (string_num);
}

static unsigned int	ft_num_length(int n)
{
	unsigned int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		length += 1;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

/*
#include <stdio.h>
int main(void)
{
	char	*a = ft_itoa(-2147483648);
	printf("%s", a);
	return (0);
}
*/
