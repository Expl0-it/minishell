/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:39:01 by codespace         #+#    #+#             */
/*   Updated: 2025/01/10 12:33:46 by codespace        ###   ########.fr       */
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
    count = 1;
    while (args[i])
    {
        if (args[i][0] != '-')
            break ;
        count++;
        i++;
    }
    return (count);
}

void	fill_cmd(t_data *data, int j, int i)
{
	int		c;
	int		k;
	
	k = 0;
	c = cmd_count(&data->args[j]);
	data->pipes[i].cmd = malloc(sizeof(char *) * (c + 1));
	while (k < c)
	{
		data->pipes[i].cmd[k] = ft_strdup(data->args[j]);
		j++;
		k++;
	}
	data->pipes[i].cmd[k] = NULL;
}

void    lexer(t_data *data)
{
    int	p;
    int	i;
	int j;

    p = pipe_count(data->args);
    data->pipes = malloc(sizeof(t_pipes) * (p + 1));
    i = 0;
	j = 0;
    while (i < p)
    {
        fill_cmd(data, j, i);
		// maybe skip all flags before this while
		while (data->args[j] != NULL && ft_strncmp(data->args[j], "|", ft_strlen(data->args[j])) != 0) {
			// save infd
			if (ft_strncmp(data->args[j], "<", ft_strlen(data->args[j])) == 0)
			{
				// open and close if its not the last one
				data->pipes[i].infile = ft_strdup(data->args[j + 1]);
			}
			else if (ft_strncmp(data->args[j], ">", ft_strlen(data->args[j])) == 0)
			{
				// open and close if its not the last one
				// check if we need to append or replace
				// set write_mode
				data->pipes[i].outfile = ft_strdup(data->args[j + 1]);
			}
			// save heredoc
			else if (ft_strncmp(data->args[j], "<<", ft_strlen(data->args[j])) == 0)
			{
				data->pipes[i].limiter = ft_strdup(data->args[j + 1]);
				data->pipes[i].heredoc = true;
			}
			// invalid infile, check if it exists and permissions
			// fds
			// pid
			else if (ft_strncmp(data->args[j], "|", ft_strlen(data->args[j])) == 0)
			{
				// open pipe
				pipe(data->pipes[i].fds); // ??
			}

			j++;
		}
		if (data->args[j] != NULL)
			j++;
		
		// print cmds
		for (int x = 0; data->pipes[i].cmd[x] != NULL; x++)
			printf("cmd: %s\n", data->pipes[i].cmd[x]);

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