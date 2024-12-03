/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:34:14 by rdavurov          #+#    #+#             */
/*   Updated: 2024/12/03 12:10:40 by codespace        ###   ########.fr       */
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
