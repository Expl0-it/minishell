/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:39:01 by codespace         #+#    #+#             */
/*   Updated: 2025/01/09 15:31:34 by codespace        ###   ########.fr       */
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
    int     j;

    i = 0;
    j = 0;
    p = pipe_count(data->args);
    data->pipes = malloc(sizeof(t_pipes) * (p + 1)); // add +1 later for NULL
    data->pipes[p] = NULL; // must check why doest work like that
    printf("pipes: %d\n", p);
    while (i < p)
    {
        c = cmd_count(&data->args[j]);
        data->pipes[i].cmd = malloc(sizeof(char *) * (++c + 1));
        int ASD = 0;
        while (ASD < c)
        {
            data->pipes[i].cmd[ASD] = ft_strdup(data->args[j]);
            j++;
            ASD++;
        }
        data->pipes[i].cmd[ASD] = NULL;
        printf("cmd: %s\n", data->pipes[i].cmd[0]);
        perror("@@@@@@@");
        i++;
        while (ft_strncmp(data->args[j], "|", ft_strlen(data->args[j])) != 0 && data->args[j])
        {
            j++;
        }
        printf("args: %s\n", data->args[j]);
        if (data->args[j])
            j++;
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