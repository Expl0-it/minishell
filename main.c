/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:34:14 by rdavurov          #+#    #+#             */
/*   Updated: 2025/01/12 20:28:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*line;

	((void)argc, (void)argv);
	init_signals();
	if (EXIT_FAILURE == init_env(&data, envp))
		exit(EXIT_FAILURE);
	while (true)
	{
		line = readline("[minishell]$ ");
		if (NULL == line)
			break;
		if (!*line)
		{
			free(line);
			continue ;
		}
		add_history(line);
		parse_input(&data, line);
		free(line);
		lexer(&data);
		// TODO: check pipe & execute
		perror("execute");
		// if (true == check_pipe)
				execute(&data);
		// cleanup
	}
}
