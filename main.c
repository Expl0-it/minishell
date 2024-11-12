/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:34:14 by rdavurov          #+#    #+#             */
/*   Updated: 2024/11/12 20:49:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	t_data	data;
	char	*input;

	while (1)
	{
		input = readline("minishell$ ");
		if (*input != '\0')
			add_history(input);
		parse_input(&data, input);
		free(input);
	}
	return (0);
}
