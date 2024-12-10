/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:00:04 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/10 13:02:26 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	echo_args(char **args, bool n_flag, int i)
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

int	ft_echo(char **args)
{
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
