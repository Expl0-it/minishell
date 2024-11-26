#include "minishell.h"

t_env	*new_env_node(char **split)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (NULL == new_node)
		return (NULL);
	new_node->key = ft_strdup(split[0]);
	new_node->val = ft_strdup(split[1]);
	if (NULL == new_node->key || NULL == new_node->val)
	{
		free(new_node->key);
		free(new_node->val);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

int	init_env(t_shell *shell, char **envp)
{
	int		i;
	char	**split;
	t_env	*new_node;
	t_env	*last_node;

	i = 0;
	shell->env = NULL;
	last_node = NULL;
	while (NULL != envp[i])
	{
		split = (char **)ft_split(envp[i], '=');
		if (NULL == split)
			return (EXIT_FAILURE);
		new_node = new_env_node(split);
		free_arr(split, -1);
		if (NULL == new_node)
			return (EXIT_FAILURE);
		if (0 == i)
			shell->env = new_node;
		else
			(last_node->next = new_node);
		last_node = new_node;
		i++;
	}
	return (EXIT_SUCCESS);
}
