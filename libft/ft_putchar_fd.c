/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:37:57 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:51:28 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Put a character in file.
 * 
 * 	Outputs the character ’c’ to the given file
 * 	descriptor. \n	 	
 * 	STDFD:
 * 	0 => stdin;
 * 	1 => stdout;
 * 	2 => stderr;
 * 
 * 	@param c The character to output
 * 	@param fd The file descriptor on which to write
 *  @return Void.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int main(void)
{
	ft_putchar_fd('c', 1);
	return (0);
}
*/
