/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:34:14 by rdavurov          #+#    #+#             */
/*   Updated: 2025/02/12 15:43:23 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	t_data		data;
	char		*line;
	extern char	**environ;

	data.envp = environ;
	init_signals();
	if (EXIT_FAILURE == init_env(&data, environ))
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
		cleanup_iter(&data);
	}
}
