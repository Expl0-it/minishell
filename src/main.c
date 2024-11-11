/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:51:01 by codespace         #+#    #+#             */
/*   Updated: 2024/11/10 20:56:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int     main(int argc, char **argv, char **envp)
{
    char    *line;
    
    while (1)
    {
        line = readline("minishell$ ");    
    }
}