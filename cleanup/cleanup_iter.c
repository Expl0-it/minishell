/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:14:13 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/13 13:41:54 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// NOTE: It will be the cleanup on every single request
static void	cleanup_pipes_s(t_data *data)
{
	int		i;
	t_pipes	*curr;

	i = 0;
	while (NULL != data->pipes[i].cmd)
	{
		curr = &data->pipes[i];
		free_str_arr(curr->cmd, -1);
		i++;
	}
	free_str_arr(data->args, -1);
	free(data->pipes);
}

void	cleanup_iter(t_data *data)
{
	// NOTE: close all open files
	// remove all temp files (like .heredoc)
	cleanup_pipes_s(data);
}
