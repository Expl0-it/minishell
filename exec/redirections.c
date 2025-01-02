#include "minishell.h"


static bool	handle_heredoc(t_pipes *curr)
{
	int	fd;
	char *input;

	input = NULL;
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (-1 == fd)
		return (false);
	if (false == read_heredoc(curr, fd, input))
		return (false);
	close(fd);
	fd = open(".heredoc", O_RDONLY, 0644);
	dup2(fd, STDIN_FILENO);
	close(fd);
	free(curr->limiter);
	curr->limiter = NULL;
	return (true);
}

static void	redirect_input(t_data *data, int i)
{
	t_pipes *curr;

	curr = &data->pipes[i];
	if (true == curr->heredoc && NULL != curr->limiter)
		handle_heredoc(curr);
	else if (0 == curr->pid)
	{	
		if (curr->infd != -1)
			dup2(curr->infd, STDIN_FILENO);
	}
	else
		dup2(curr->fds[0], STDIN_FILENO);
}

static void	redirect_output(t_data *data, int i)
{
	t_pipes *curr;

	curr = &data->pipes[i];
	if (-1 != curr->outfd)
		dup2(curr->outfd, STDOUT_FILENO);
	else
		dup2(curr->fds[1], STDOUT_FILENO);

}

void	handle_redirections(t_data *data, int i)
{
	redirect_input(data, i);
	redirect_output(data, i);
}
