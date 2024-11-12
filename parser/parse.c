/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:50:45 by rdavurov          #+#    #+#             */
/*   Updated: 2024/11/12 20:51:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	skip_spaces(char **input)
{
	while (*(*input) == ' ')
		(*input)++;
}

int		count_comands(char *input)
{
	int		count;

	count = 0;
	skip_spaces(&input);
	while (*input != '\0')
	{
		if (*input == '"')
		{
			input++;
			while (*input != '"')
				input++;
			input++;
		}
		if (*input == ' ')
		{
			skip_spaces(&input);
			count++;
		}
		input++;		
	}
	return (count);
}

void	parse_input(t_data *data, char *input)
{
	int		count;
	(void)data;
	
	count = count_comands(input);
	printf("%d", count);
}