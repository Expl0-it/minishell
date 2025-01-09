/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:39:01 by codespace         #+#    #+#             */
/*   Updated: 2025/01/08 15:13:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     pipe_count(char **args)
{
    int     count;
    int     i;

    i = 0;
    count = 1;
    while (args[i])
    {
        if (args[i][0] == '|')
            count++;
        i++;
    }
    return (count);
}

int     cmd_count(char **args)
{
    int     count;
    int     i;

    i = 1;
    count = 0;
    while (args[i])
    {
        if (args[i][0] != '-')
            break ;
        count++;
        i++;
    }
    return (count);
}

void    lexer(t_data *data)
{
    int     p;
    int     c;
    int     i;

    i = 0;
    p = pipe_count(data->args);
    c = cmd_count(data->args);
    data->pipes = malloc(sizeof(t_pipes) * p); // add +1 later for NULL
    while (i < p)
    {
        data->pipes[i].cmd = malloc(sizeof(char *) * c++); // add +1 later for NULL
        data->pipes[i].cmd[0] = data->args[i];
        data->pipes[i].cmd[1] = NULL;
        i++;      
    }
    
    
}

// typedef struct s_pipes
// {
// 	char			**cmd; // cmd + arg (like: [ls, -R -la, NULL] or [echo, -n, NULL] or [pwd, NULL])
// 	char			*limiter; // when using heredoc: << limiter || else NULL
// 	char			*infile; // NOTE: those should be also helpful to you to handle opening the files and put fds to struct
// 	char			*outfile; // NOTE: those should be also helpful to you to handle opening the files and put fds to struct
// 	int				fds[2];
// 	int				infd; // when redirecting input < infile
// 	int				outfd; // when redirecting output > outfile
// 	pid_t			pid; // current proccess pid
// 	bool			heredoc; // do we use heredoc (input redirection "<<")
// 	bool			invalid_infile; // does the infile exist and do we have premissions to it?
// 	t_write_mode	write_mode; // do we use replace ">" or append ">>" file's contents with output redirection
// }			t_pipes;