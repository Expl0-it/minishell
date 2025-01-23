/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:39:01 by codespace         #+#    #+#             */
/*   Updated: 2025/01/23 12:29:08 by mamichal         ###   ########.fr       */
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
    int     i;

    i = 0;
    while (args[i]
		&& ft_strncmp(args[i], "|", ft_strlen(args[i]))
		&& ft_strncmp(args[i], "<", ft_strlen(args[i]))
		&& ft_strncmp(args[i], ">", ft_strlen(args[i]))
		&& ft_strncmp(args[i], ">>", ft_strlen(args[i]))
		&& ft_strncmp(args[i], "<<", ft_strlen(args[i])))
        i++;
    return (i);
}

int	fill_cmd(t_data *data, int j, int i)
{
	int		c;
	int		k;
	
	k = 0;
			perror("");	
	c = cmd_count(&data->args[j]);
	data->pipes[i].cmd = malloc(sizeof(char *) * (c + 1));
	while (k < c)
	{
		data->pipes[i].cmd[k] = ft_strdup(data->args[j]);
		j++;
		k++;
	}
	data->pipes[i].cmd[k] = NULL;
	return (c);
}

void initiate_pipe(t_pipes *pipe)
{
	pipe->infd = 0;
	pipe->outfd = 0;
	pipe->pid = 0;
	pipe->heredoc = false;
	pipe->invalid_infile = false;
	pipe->write_mode = REPLACE;
	pipe->infile = NULL;
	pipe->outfile = NULL;
	pipe->limiter = NULL;
}

void	lexer(t_data *data)
{
	int p = pipe_count(data->args);
	int j = 0;
	int c;
	// NOTE: WHEN ALLOCATING WITH CALLOC IT DOESNT SEGFAULT ANYMORE
	data->pipes = ft_calloc(p + 1, sizeof(t_pipes));
	/*data->pipes = malloc(sizeof(t_pipes *) * (p + 1));*/
	for (int i = 0; i < p; i++)
	{
		initiate_pipe(&data->pipes[i]);
		c = fill_cmd(data, i, j);		
		while (j < c * (i + 1))
			j++;
		while (data->args[j] != NULL && ft_strncmp(data->args[j], "|", ft_strlen(data->args[j])) != 0)
		{
			// if (ft_strncmp(data->args[j], "<", ft_strlen(data->args[j])) == 0)
			// {
			// 	data->pipes[i].infd = open(data->args[j + 1], O_RDONLY);
			// 	if (data->pipes[i].infile)
			// 		close(data->pipes[i].infd);
			// 	data->pipes[i].infile = ft_strdup(data->args[j + 1]);
			// }
			// else if (ft_strncmp(data->args[j], ">", 1) == 0)
			// {
			// 	int		flag;
				
			// 	flag = O_TRUNC;
			// 	data->pipes[i].write_mode = REPLACE;
			// 	if (ft_strncmp(data->args[j], ">>", 2) == 0)
			// 	{
			// 		flag = O_APPEND;
			// 		data->pipes[i].write_mode = APPEND;
			// 	}
			// 	data->pipes[i].outfd = open(data->args[j + 1], O_WRONLY | O_CREAT | flag, 0644);
			// 	if (data->pipes[i].outfile)
			// 		close(data->pipes[i].outfd);
			// 	data->pipes[i].outfile = ft_strdup(data->args[j + 1]);
			// }
			// else if (ft_strncmp(data->args[j], "<<", ft_strlen(data->args[j])) == 0)
			// {
			// 	data->pipes[i].limiter = ft_strdup(data->args[j + 1]);
			// 	data->pipes[i].heredoc = true;
			// }
			j++;
		}
		// for (int x = 0; data->pipes[i].cmd[x] != NULL; x++)
		// {
		// 	printf("cmd: %s\n", data->pipes[i].cmd[x]);
		// }
	}
}
