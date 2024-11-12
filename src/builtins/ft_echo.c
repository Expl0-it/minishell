/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:00:04 by mamichal          #+#    #+#             */
/*   Updated: 2024/11/12 13:16:54 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	echo_args(const char **args, bool n_flag, int i)
{
	if (NULL == args || NULL == args[i])
		return ;
	printf("%s", args[i]);
	i++;
	while (args[i])
	{
		printf(" %s", args[i]);
		i++;
	}
	if (false == n_flag)
		printf("\n");
}

int	ft_echo(const char **args)
{
	// TODO: TESTS
	bool	n_flag;
	int		i;

	n_flag = false;
	i = 1;
	if (NULL == args || NULL == *args)
		return (EXIT_FAILURE);
	if (NULL != args[i] && ft_strncmp(args[i], "-n", 3) == 0)
	{
		n_flag = true;
		i++;
	}
	echo_args(args, n_flag, i);
	return (EXIT_SUCCESS);
}
