/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:17:47 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/15 09:09:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_unclosed_quotes(char *line)
{
	short	quote;

	quote = 0;
	while (*line)
	{
		if (is_quote(*line))
		{
			if (!quote)
				quote = *line;
			else if (quote == *line)
				quote = 0;
		}
		line++;
	}
	if (quote)
	{
		ft_putstr_fd("error: unclosed quote\n", 2);
		exit(1);
	}
}

short	set_env_str(char *val, int key_len, char **line, char **arg)
{
	if (*arg)
		*arg += ft_strlcpy(*arg, val, ft_strlen(val) + 1);
	*line += key_len;
	return (ft_strlen(val));
}

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
