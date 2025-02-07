#include "minishell.h"

// NOTE: It will be the cleanup on every single request
static void	cleanup_pipes_s(t_data *data)
{
	int	i;
	t_pipes	*curr;

	i = 0;

	while (NULL != data->pipes[i].cmd)
	{
		curr = &data->pipes[i];
		free_str_arr(curr->cmd, -1);
		i++;
	}
}

void	cleanup_req(t_data *data)
{
	cleanup_pipes_s(data);
}

