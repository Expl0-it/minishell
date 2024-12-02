#include "minishell.h"

t_env	*new_env_node(char **split)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (NULL == new_node)
		return (NULL);
	new_node->key = ft_strdup(split[0]);
	if (NULL == split[2])
		new_node->val = ft_strdup(split[1]);
	else
		new_node->val = concat_split(split, '=', 1);
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

