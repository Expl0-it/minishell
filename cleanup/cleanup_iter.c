/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:14:13 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/15 09:53:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fds(t_pipes *pipe)
{
	if (pipe->infd > 2)
	{
		close(pipe->infd);
		pipe->infd = -1;
	}
	if (pipe->outfd > 2)
	{
		close(pipe->outfd);
		pipe->outfd = -1;
	}
	if (pipe->old_outfd > 2)
	{
		close(pipe->old_outfd);
		pipe->old_outfd = -1;
	}
	if (pipe->fds[0] > 2)
	{
		close(pipe->fds[0]);
		pipe->fds[0] = -1;
	}
	if (pipe->fds[1] > 2)
	{
		close(pipe->fds[1]);
		pipe->fds[1] = -1;
	}
}

static void	cleanup_pipes_s(t_data *data)
{
	int		i;
	t_pipes	*curr;

	i = 0;
	while (NULL != data->pipes[i].cmd)
	{
		curr = &data->pipes[i];
		close_fds(curr);
		if (curr->limiter)
			free(curr->limiter);
		if (curr->infile)
			free(curr->infile);
		if (curr->outfile)
			free(curr->outfile);
		free_str_arr(curr->cmd, -1);
		i++;
	}
	free(data->pipes);
}

void	cleanup_iter(t_data *data)
{
	int	i;

	i = 0;
	while (data->args[i])
	{
		free(data->args[i]);
		data->args[i] = NULL;
		i++;
	}
	free(data->args);
	data->args = NULL;
	cleanup_pipes_s(data);
}
