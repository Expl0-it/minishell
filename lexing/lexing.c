/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:39:01 by codespace         #+#    #+#             */
/*   Updated: 2025/02/11 12:03:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	initiate_pipe(t_pipes *pipe)
{
	pipe->old_outfd = STDOUT_FILENO;
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

static int	pipes_count(char **args)
{
	int	pipes;

	pipes = 0;
	while (*args)
	{
		if (!ft_strncmp(*args, "|", 1))
			pipes++;
		args++;
	}
	return (pipes + 1);
}

static int	fill_cmd(char **args, t_pipes *pipe)
{
	int	i;

	i = 0;
	while (args[i]
		&& ft_strncmp(args[i], "|", 2)
		&& ft_strncmp(args[i], "<", 2)
		&& ft_strncmp(args[i], ">", 2)
		&& ft_strncmp(args[i], ">>", 3)
		&& ft_strncmp(args[i], "<<", 3))
	{
		if (pipe)
			pipe->cmd[i] = ft_strdup(args[i]);
		i++;
	}
	return (i);
}

static void	fill_pipes(t_pipes *pipe, char **args, int *j)
{
	int	cmd_count;

	cmd_count = fill_cmd(args + *j, NULL);
	initiate_pipe(pipe);
	pipe->cmd = ft_calloc(cmd_count + 1, sizeof(t_pipes));
	*j += fill_cmd(args + *j, pipe);
	if (ft_strncmp(args[0], "<", 2) == 0 && args[1] && args[2])
		pipe->cmd[0] = ft_strdup(args[2]);
	while (args[*j] && ft_strncmp(args[*j], "|", 2))
	{
		if (args[*j] && !ft_strncmp(args[*j], ">", 1))
			set_append(args, *j, pipe);
		else if (ft_strncmp(args[*j], "<", 2) == 0)
			set_redirection(args, *j, pipe);
		else if (!ft_strncmp(args[*j], "<<", 3))
			set_heredoc(pipe, args[*j + 1]);
		(*j)++;
	}
	if (args[*j])
		(*j)++;
	if (pipe->outfd != STDOUT_FILENO)
	{
		pipe->old_outfd = STDOUT_FILENO;
		dup2(pipe->outfd, STDOUT_FILENO);
		close(pipe->outfd);
	}
}

void	lexer(t_data *data)
{
	int	i;
	int	j;
	int	pipes;

	pipes = pipes_count(data->args);
	data->pipes = ft_calloc(pipes + 1, sizeof(t_pipes));
	i = 0;
	j = 0;
	while (i < pipes)
	{
		fill_pipes(data->pipes + i, data->args, &j);
		i++;
	}
}
