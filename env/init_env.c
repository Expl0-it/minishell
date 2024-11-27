#include "minishell.h"

// NOTE: used in case when enviromental variable has '=' inside it
static char	*concat_split(char **split, char split_delimeter, int i_start)
{
	int		i;
	int		len;
	int		curr;
	char	*ret;

	i = i_start;
	len = 0;
	while (split[i])
		len += ft_strlen(split[i++]) + 1;
	ret = (char *)ft_calloc(len, sizeof(char));
	i = i_start;
	curr = 0;
	while (split[i])
	{
		curr = ft_strlcat(ret, split[i], len);
		if (NULL != split[++i])
			ret[+curr] = split_delimeter;
	}
	return (ret);
}

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
