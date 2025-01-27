/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:39:01 by codespace         #+#    #+#             */
/*   Updated: 2025/01/27 16:41:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void initiate_pipe(t_pipes *pipe)
{
	pipe->old_outfd = -1;
	pipe->infd = STDIN_FILENO;
	pipe->outfd = STDOUT_FILENO;
	pipe->pid = 0;
	pipe->heredoc = false;
	pipe->invalid_infile = false;
	pipe->write_mode = REPLACE;
	pipe->infile = NULL;
	pipe->outfile = NULL;
	pipe->limiter = NULL;
}

int	pipes_count(char **args)
{
	int pipes;

	pipes = 0;
	while (*args)
	{
		if (!ft_strncmp(*args, "|", 1))
			pipes++;
		args++;
	}
	return (pipes + 1);
}

int	fill_cmd(char **args, t_pipes *pipe)
{
	int	i;

	i = 0;
	while (args[i]
		&& ft_strncmp(args[i], "|", ft_strlen(args[i]))
		&& ft_strncmp(args[i], "<", ft_strlen(args[i]))
		&& ft_strncmp(args[i], ">", ft_strlen(args[i]))
		&& ft_strncmp(args[i], ">>", ft_strlen(args[i]))
		&& ft_strncmp(args[i], "<<", ft_strlen(args[i])))
	{
		if (pipe)
			pipe->cmd[i] = ft_strdup(args[i]);
		i++;
	}
	return (i);
}

void print_pipe_debug(t_pipes *pipe, int i)
{
	printf("pipes[%d]:\n", i);
	printf("pipe->cmd: ");
	for (int i = 0; pipe->cmd[i]; i++)
		printf("%s ", pipe->cmd[i]);
	printf("\n");
	printf("pipe->limiter: %s\n", pipe->limiter);
	printf("pipe->infile: %s\n", pipe->infile);
	printf("pipe->outfile: %s\n", pipe->outfile);
	printf("pipe->old_outfd: %d\n", pipe->old_outfd);
	printf("pipe->infd: %d\n", pipe->infd);
	printf("pipe->outfd: %d\n", pipe->outfd);
	printf("pipe->pid: %d\n", pipe->pid);
	printf("pipe->heredoc: %d\n", pipe->heredoc);
	printf("pipe->invalid_infile: %d\n", pipe->invalid_infile);
	printf("pipe->write_mode: %d\n", pipe->write_mode);
	printf("\n");
}

void	fill_pipes(t_pipes *pipe, char **args, int *j)
{
	int cmd_count;

	cmd_count = fill_cmd(args + *j, NULL);
	initiate_pipe(pipe);
	pipe->cmd = ft_calloc(cmd_count + 1, sizeof(t_pipes));
	*j += fill_cmd(args + *j, pipe);
	while (args[*j] && ft_strncmp(args[*j], "|", 1))
	{

		// Create a separate function for this if 
		if (args[*j] && !ft_strncmp(args[*j], ">", 1))
		{
			int flag;

			flag = O_TRUNC;
			if (!ft_strncmp(args[*j], ">>", 2))
			{
				flag = O_APPEND;
				pipe->write_mode = APPEND;
			}
			if (pipe->outfile)
			{
				close(pipe->outfd);
				free(pipe->outfile);
			}
			pipe->outfd = open(args[*j + 1], O_WRONLY | O_CREAT | flag, 0644);
			pipe->outfile = ft_strdup(args[*j + 1]);
		}

		// Create a separate function for this else if
		else if (ft_strncmp(args[*j], "<<", 2))
		{
			pipe->limiter = ft_strdup(args[*j + 1]);
			pipe->heredoc = true;
		}

		(*j)++;
	}

	if (args[*j])
		(*j)++;
	if (pipe->outfd != STDOUT_FILENO)
	{
		pipe->old_outfd = dup(STDOUT_FILENO);
		dup2(pipe->outfd, STDOUT_FILENO);
		close(pipe->outfd);
	}
}

void	lexer(t_data *data)
{
	int i;
	int j;
	int pipes;

	pipes = pipes_count(data->args);
	data->pipes = ft_calloc(pipes + 1, sizeof(t_pipes));
	i = 0;
	j = 0;
	while (i < pipes)
	{
		fill_pipes(data->pipes + i, data->args, &j);
		i++;		
	}

	// for (int i = 0; i < pipes; i++)
	// {
	// 	print_pipe_debug(data->pipes + i, i);
	// }
	// perror("super");
}





// 			// if (ft_strncmp(data->args[j], "<", ft_strlen(data->args[j])) == 0)
// 			// {
// 			// 	data->pipes[i].infd = open(data->args[j + 1], O_RDONLY);
// 			// 	if (data->pipes[i].infile)
// 			// 		close(data->pipes[i].infd);
// 			// 	data->pipes[i].infile = ft_strdup(data->args[j + 1]);
// 			// }
// 			// else if (ft_strncmp(data->args[j], "<<", ft_strlen(data->args[j])) == 0)
// 			// {
// 			// 	data->pipes[i].limiter = ft_strdup(data->args[j + 1]);
// 			// 	data->pipes[i].heredoc = true;
// 			// }