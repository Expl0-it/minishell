#include "minishell.h"

//it has seg fault

int	init_env(t_data *data, char **envp)
{
	int		i;
	char	**split;
	t_env	*new_node;
	t_env	*last_node;

	i = 0;
	data->env = NULL;
	last_node = NULL;
	while (NULL != envp[i])
	{
		split = (char **)ft_split(envp[i], '=');
		if (NULL == split)
			return (EXIT_FAILURE);
		new_node = new_env_node(split);
		free_str_arr(split, -1);
		if (NULL == new_node)
			return (EXIT_FAILURE);
		if (0 == i)
			data->env = new_node;
		else
			(last_node->next = new_node);
		last_node = new_node;
		i++;
	}
	return (EXIT_SUCCESS);
}
