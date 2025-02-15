/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:12:58 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/15 09:52:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_operators(t_pipes *pipe, char **args, int j)
{
	if (args[j] && !ft_strncmp(args[j], ">", 1))
		set_append(args, j, pipe);
	else if (ft_strncmp(args[j], "<", 2) == 0)
		set_redirection(args, j, pipe);
	else if (!ft_strncmp(args[j], "<<", 3))
		set_heredoc(pipe, args[j + 1]);	
}

void	set_append(char **args, int j, t_pipes *pipe)
{
	int	flag;

	flag = O_TRUNC;
	if (ft_strlen(args[j]) > 2)
		return ;
	if (!ft_strncmp(args[j], ">>", 3))
	{
		flag = O_APPEND;
		pipe->write_mode = APPEND;
	}
	if (pipe->outfile)
	{
		close(pipe->outfd);
		free(pipe->outfile);
	}
	pipe->outfd = open(args[j + 1], O_WRONLY | O_CREAT | flag, 0644);
	pipe->outfile = ft_strdup(args[j + 1]);
}

void	set_heredoc(t_pipes *pipe, char *arg)
{
	pipe->limiter = ft_strdup(arg);
	pipe->heredoc = true;
}

void	set_redirection(char **args, int j, t_pipes *pipe)
{
	pipe->infd = open(args[j + 1], O_RDONLY);
	if (pipe->infile)
		close(pipe->infd);
	pipe->infile = ft_strdup(args[j + 1]);
}
