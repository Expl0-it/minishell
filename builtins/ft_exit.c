/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:21:42 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/12 16:07:44 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: TESTS
int	ft_exit(t_data *data, char **args)
{
	if (NULL == args[1])
		data->exit_code = EXIT_SUCCESS;
	else if (NULL != args[2])
	{
		ft_putendl_fd(ERR_EXIT_MANY_ARGS, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else
		data->exit_code = (uint8_t)ft_atoi(args[1]);
	cleanup_iter(data);
	cleanup_exit(data);
	exit(data->exit_code);
	return (data->exit_code);
}
