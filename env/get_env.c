#include "minishell.h"

t_env	*get_env_node(t_env *env, char *key)
{
	int	len;

	if (NULL == key)
		return (NULL);
	len = ft_strlen(key);
	while (NULL != env)
	{
		if (0 == ft_strncmp(key, env->key, len + 1))
			return (env);
		env = env->next;
	}
	return (NULL);
}

t_env	*get_env_last_node(t_env *env)
{
	t_env	*last_node;

	last_node = env;
	while (NULL != last_node && NULL != last_node->next)
		last_node = last_node->next;
	return (last_node);
}

int	get_env_size(t_env *env)
{
	int	size;

	size = 0;
	while (NULL != env)
	{
		size++;
		env = env->next;
	}
	return (size);
}

char	*get_env_val(t_env *env, char *key)
{
	int	len;

	if (NULL == key)
		return (NULL);
	len = ft_strlen(key);
	while (NULL != env)
	{
		if (0 == ft_strncmp(key, env->key, len + 1))
			return (env->val);
		env = env->next;
	}
	return (NULL);
}
