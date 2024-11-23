/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:50:45 by rdavurov          #+#    #+#             */
/*   Updated: 2024/11/23 21:33:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	skip_spaces(char **input)
{
	while (*(*input) == ' ')
		(*input)++;
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
	(void)data;
	
	count = count_commands(input);
	printf("%d", count);
}