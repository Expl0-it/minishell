/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:44:47 by codespace         #+#    #+#             */
/*   Updated: 2024/11/12 20:44:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     main(int argc, char **argv, char **envp)
{
    char    *line;
    
    while (1)
    {
        line = readline("minishell$ ");
    }
}
