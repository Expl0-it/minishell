#include "minishell.h"

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
