/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:14:45 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/09 19:17:32 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_signals(void)
{
	signal(SIGINT, sig_int);
	signal(SIGTERM, sig_term);
	signal(SIGQUIT, SIG_IGN);
}
