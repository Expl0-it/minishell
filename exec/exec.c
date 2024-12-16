/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:49:26 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/16 19:11:30 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(t_data *data)
{
	int	i;
	uint8_t	res;
	(void)res;

	i = 0;
	open_pipes(data);
	while (data->pipes[i].cmd)
	{
		// TODO:
		i++;
	}
	close_pipes(data);
}
