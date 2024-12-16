/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:51:38 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/16 13:02:18 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: free all neccesary vairables and close open fds
void	err_exit(t_data *data, char *msg, t_err_exit status)
{
	free_env(data->env);
	if (NULL != msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	exit(status);
}
