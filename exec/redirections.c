#include "minishell.h"

void	handle_redirections(t_data *data, int i)
{
	redirect_input(data, i);
	redirect_output(data, i);
}
