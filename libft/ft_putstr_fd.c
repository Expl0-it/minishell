/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:38:57 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:19 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Put a string in file.
 * 
 * 	Outputs the string 's' to the given file
 * 	descriptor.
 * 	STDFD:
 * 	0 => stdin;
 * 	1 => stdout;
 * 	2 => stderr;
 * 
 * 	@param s The string to output
 * 	@param fd The file descriptor on which to write
 *  @return Void.
 */
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/*
int main(void)
{
	ft_putstr_fd("abc", 1);
	return (0);
}
*/
