/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:21:42 by mamichal          #+#    #+#             */
/*   Updated: 2024/11/12 21:52:22 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **args, t_shell *shell)
{
	// TODO: TESTS
	if (NULL == args[1])
		shell->exit_code = EXIT_SUCCESS;
	else if (NULL != args[2])
	{
		ft_putendl_fd(ERR_EXIT_MANY_ARGS, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else
		shell->exit_code = (uint8_t)ft_atoi(args[1]);
	return (shell->exit_code);
}
