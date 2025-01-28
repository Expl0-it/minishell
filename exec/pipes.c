/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:31:12 by mamichal          #+#    #+#             */
/*   Updated: 2025/01/28 12:15:35 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// decide on return type depending on cleanup
void	open_pipes(t_data *data)
{
	int		i;

	i = 0;
	while (NULL != data->pipes && NULL != data->pipes[i].cmd)
	{
		if (pipe(data->pipes[i].fds) < 0)
			err_exit(data, "pipe failure\n", PIPE_ERR);
		i++;
	}
}

void	close_pipes(t_data *data)
{
	int		i;

	i = 0;
	while (NULL != data->pipes && NULL != data->pipes[i].cmd)
	{
		close(data->pipes[i].fds[0]);
		close(data->pipes[i].fds[1]);
		i++;
	}
}

void	close_useless_pipes(t_data *data, int i_pipe)
{
	int		i_curr;

	i_curr = 0;
	while (NULL != data->pipes && NULL != data->pipes[i_curr].cmd)
	{
		if (i_pipe != i_curr)
			close(data->pipes[i_curr].fds[1]);
		if (i_pipe - 1 != i_curr)
			close(data->pipes[i_curr].fds[0]);
		i_curr++;
	}
}
