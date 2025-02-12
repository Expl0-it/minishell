/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:07:52 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/12 16:07:53 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// NOTE: it will be the cleanup on program exit (ctrl+D / exit command)
void	cleanup_exit(t_data *data)
{
	free_env(data->env);
	rl_clear_history();
}
