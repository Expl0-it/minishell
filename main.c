/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:34:14 by rdavurov          #+#    #+#             */
/*   Updated: 2024/12/09 18:26:22 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*line;

	((void)argc, (void)argv);
	if (EXIT_FAILURE == init_env(&data, envp))
		exit(EXIT_FAILURE);
	//handle signals
	while (true)
	{
		ft_env(&data);
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
		// TODO: check pipe & execute
		// if (true == check_pipe)
		//		execute(&data);
		// cleanup
	}
}
