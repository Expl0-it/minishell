/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:09:29 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/13 13:15:23 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	read_heredoc(t_pipes *curr, int fd, char *input)
{
	while (1)
	{
		input = get_next_line(STDIN_FILENO);
		if (NULL == input)
			return (false);
		if (!ft_strncmp(curr->limiter, input, ft_strlen(curr->limiter)))
		{
			free(input);
			break ;
		}
		ft_putstr_fd(input, fd);
		free(input);
	}
	return (true);
}

static bool	handle_heredoc(t_pipes *curr)
{
	int		fd;
	char	*input;

	input = NULL;
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (-1 == fd)
		return (false);
	if (false == read_heredoc(curr, fd, input))
		return (false);
	close(fd);
	curr->infd = open(".heredoc", O_RDONLY, 0644);
	free(curr->limiter);
	curr->limiter = NULL;
	return (true);
}

static void	redirect_input(t_data *data, int i)
{
	t_pipes	*curr;

	curr = &data->pipes[i];
	if (true == curr->heredoc && NULL != curr->limiter)
		handle_heredoc(curr);
	if (curr->infd != STDIN_FILENO)
		dup2(curr->infd, STDIN_FILENO);
	else if (0 < i)
		dup2(data->pipes[i - 1].fds[0], STDIN_FILENO);
}

static void	redirect_output(t_data *data, int i)
{
	t_pipes	*curr;

	curr = &data->pipes[i];
	if (STDOUT_FILENO != curr->outfd)
	{
		if (STDOUT_FILENO != curr->outfd)
		{
			if (REPLACE == curr->write_mode)
				curr->outfd = open(curr->outfile, \
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else
				curr->outfd = open(curr->outfile, \
					O_WRONLY | O_CREAT | O_APPEND, 0644);
			dup2(curr->outfd, STDOUT_FILENO);
		}
	}
	else if (NULL != data->pipes[i + 1].cmd)
		dup2(curr->fds[1], STDOUT_FILENO);
}

void	handle_redirections(t_data *data, int i)
{
	redirect_output(data, i);
	redirect_input(data, i);
}
