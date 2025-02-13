/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:17:47 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/13 12:10:52 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_spaces(char **line)
{
	while (is_space(**line))
		(*line)++;
}

bool	is_space(char c)
{
	return (c == ' ');
}

bool	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}
