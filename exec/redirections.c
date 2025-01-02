#include "minishell.h"


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
