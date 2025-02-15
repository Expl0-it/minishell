/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:17:03 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/15 09:09:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static short	process_env(t_data *data, char **line, char **arg)
{
	t_env	*current;
	char	*exit_code_str;

	(*line)++;
	current = data->env;
	exit_code_str = ft_itoa((int)data->cmd_exit_code);
	if (!ft_strncmp("?", *line, 1))
		return (set_env_str(exit_code_str, 1, line, arg));
	while (current)
	{
		if (!ft_strncmp(current->key, *line, ft_strlen(current->key)))
			return (set_env_str(current->val, ft_strlen(current->key), line, arg));
		current = current->next;
	}
	return (0);
}

static short	process_quoted_arg(t_data *data, char **line, \
			short *count, char *arg)
{
	short	n;
	char	quote;

	n = 0;
	quote = *(*line)++;
	while (**line != quote)
	{
		if (quote == '"' && **line == '$' && data)
			n += process_env(data, line, &arg);
		else
		{
			if (arg)
				*arg++ = **line;
			(*line)++;
			n++;
		}
	}
	(*line)++;
	if (count)
		(*count)++;
	return (n);
}

static short	process_arg(t_data *data, char *line, char *arg)
{
	short	n;

	n = 0;
	if (is_quote(*line))
		return (process_quoted_arg(data, &line, NULL, arg));
	while (!is_space(*line) && !is_quote(*line) && *line)
	{
		if (data && *line == '$')
			n += process_env(data, &line, &arg);
		else
		{
			if (arg)
				*arg++ = *line;
			line++;
			n++;
		}
	}
	return (n);
}

static short	count_args(char *line)
{
	short	count;

	count = 0;
	while (*line)
	{
		if (is_quote(*line))
			process_quoted_arg(NULL, &line, &count, NULL);
		else if (is_space(*line))
		{
			if (!is_quote(*(line - 1)))
				count++;
			skip_spaces(&line);
		}
		else
		{
			line++;
			if (is_quote(*line) || !*line)
				count++;
		}
	}
	return (count);
}

void	parse_input(t_data *data, char *line)
{
	short	i;
	short	n;
	short	m;

	check_unclosed_quotes(line);
	n = count_args(line);
	data->args = malloc(sizeof(char *) * (n + 1));
	data->args[n] = NULL;
	i = 0;
	while (i < n)
	{
		m = process_arg(data, line, NULL);
		data->args[i] = malloc(sizeof(char) * (m + 1));
		data->args[i][m] = '\0';
		// printf("Addr inside - %p\n", data->args[i]);
		process_arg(data, line, data->args[i]);
		if (is_quote(*line))
			process_quoted_arg(data, &line, NULL, NULL);
		else
			line += process_arg(NULL, line, NULL);
		skip_spaces(&line);
		i++;
	}
}
