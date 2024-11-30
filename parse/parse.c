/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:50:45 by rdavurov          #+#    #+#             */
/*   Updated: 2024/11/30 18:15:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	skip_spaces(char **input)
{
	while (*(*input) == ' ')
		(*input)++;
}

int		char_count(char *input, int *i)
{
	int		len;
	char	quote;

	len = 0;
	while (input[*i] != ' ' && input[*i] != '\0')
	{
		if  (input[*i] == '"' || input[*i] == '\'')
		{
			quote = input[*i];
			(*i)++;
			while (input[*i] != quote)
			{
				len++;
				(*i)++;
			}
			(*i)++;
			while (input[*i] == ' ')
				(*i)++;
			return len;
		}
		else
		{
			len++;
			(*i)++;
			if (input[*i] == '\'' || input[*i] == '"')
				break;
		}
	}
	while (input[*i] == ' ')
		(*i)++;
	return len;
}

int		count_commands(char *input)
{
	int		count;
	char	quote;

	count = 0;
	skip_spaces(&input);
	while (*input != '\0')
	{
		while (*input == '"' || *input == '\'')
		{
			quote = *input;
			count++;
			input++;
			while (*input != quote)
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


void	fill_cmd(char **input, char **argv)
{
	int		j;
	char	quote;
	
	j = 0;
	while (**input != ' ' && **input != '\0')
	{
		if (**input == '"' || **input == '\'')
		{
			quote = **input;
			(*input)++;
			argv[0][j] = **input;
			j++;
			while (**input != quote)
			{
				argv[0][j] = **input;
				j++;
				(*input)++;
			}
			(*input)++;
			argv[0][j] = '\0';
			return ;
		}
		else
		{
			argv[0][j] = **input;
			j++;
			(*input)++;
		}
	}
	skip_spaces(input);
	argv[0][j] = '\0';
}

//fix the "hfdjkh hdsjk''hfdjsk hdjk" case

void	parse_input(t_data *data, char *input)
{
	int		count;
	int 	i;
	int		j;
	
	i = 0;
	j = 0;
	count = count_commands(input);
	data->argv = (char **)malloc(sizeof(char *) * count + 1);
	
	skip_spaces(&input);
	while (i < count)
	{
		data->argv[i] = (char *)malloc(sizeof(char) * char_count(input, &j) + 1);
		fill_cmd(&input, data->argv + i);
		i++;
	}
	data->argv[i] = NULL;
	i = 0;
	while (data->argv[i] != NULL)
	{
		printf("data->argv[%d] = %s\n", i, data->argv[i]);
		i++;
	}
}