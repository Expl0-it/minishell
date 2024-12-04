/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:34:14 by rdavurov          #+#    #+#             */
/*   Updated: 2024/12/04 11:42:38 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	char	*input;

	((void)ac, (void)av);
	while (1)
	{
		input = readline("minishell$ ");
		if (*input != '\0')
			add_history(input);
		init_env(&data, envp);
		parse_input(&data, input);
		free(input);
	}
	return (0);
}

/* NOTE: Prototyped new main

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*line;

	((void)argc, (void)argv);
	if (EXIT_FAILURE == init_env(&data, envp))
		exit(EXIT_FAILURE);
	while (true)
	{
		//handle signals
		line = readline("[minishell]$");
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
		// TODO: check pipe & execute
		// if (true == check_pipe)
		//		execute(&data);
		// cleanup
	}
}
*/
