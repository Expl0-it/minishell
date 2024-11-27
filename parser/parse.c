/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:50:45 by rdavurov          #+#    #+#             */
/*   Updated: 2024/11/27 19:37:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	skip_spaces(char **input)
{
	while (*(*input) == ' ')
		(*input)++;
}

int		char_count(char **input)
{
	int		len;

	len = 0;
	while (*(*input) != ' ' && *(*input) != '\0')
	{
		if (*(*input) == '"' || *(*input) == '\'')
		{
			(*input)++;
			while (*(*input) != '"' && *(*input) != '\'')
			{
				len++;
				(*input)++;
			}
			(*input)++;
			skip_spaces(input);
			return len;
		}
		else
		{
			len++;
			(*input)++;
			if (*(*input) == '\'' || *(*input) == '"')
				break;
		}
	}
	skip_spaces(input);
	return len;
}

int		count_commands(char *input)
{
	int		count;

	count = 0;
	skip_spaces(&input);
	while (*input != '\0')
	{
		while (*input == '"' || *input == '\'')
		{
			count++;
			input++;
			while (*input != '"' && *input != '\'')
				input++;
			input++;
			skip_spaces(&input);
		}
		if (*input == ' ')
		{
			count++;
			skip_spaces(&input);
		}
		else
			if (*input != '\0' && *input != '"' && *input != '\'')	
				input++;
		if ((*(input + 1) == '\'' || *(input + 1) == '"') && *input != ' ')
			count++;
		if (*(input - 1) != ' ' && *(input - 1) != '"' && *(input - 1) != '\'' && *input == '\0')
			count++;
	}
	return (count);
}

void	parse_input(t_data *data, char *input)
{
	int		count;
	int i;
	
	i = 0;
	count = count_commands(input);
	data->argv = (char **)malloc(sizeof(char *) * count + 1);
	
	skip_spaces(&input);
	while (i < count)
	{
		printf("char_count: %d\n", char_count(&input));
		i++;
		// data->argv[i] = (char *)malloc(sizeof(char) * char_count(&input) + 1);
	}
}