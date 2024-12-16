/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:31:12 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/16 19:15:45 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// decide on return type depending on cleanup
void	open_pipes(t_data *data)
{
	int		i;
	t_pipes	*curr;

	i = 0;
	while (NULL != data->pipes[i].cmd)
	{
		curr = &data->pipes[i];
		curr->fds[0] = curr->infd;
		curr->fds[1] = curr->outfd;
		if (pipe(curr->fds) < 0)
			err_exit(data, "pipe failure\n", PIPE_ERR);
		i++;
	}
}

void	close_pipes(t_data *data)
{
	int		i;
	t_pipes	*curr;

	i = 0;
	while (data->pipes[i].cmd)
	{
		curr = &data->pipes[i];
		close(curr->fds[0]);
		close(curr->fds[1]);
		i++;
	}
}
