#include "minishell.h"

// NOTE: used in case when enviromental variable has '=' inside it
char	*concat_split(char **split, char split_delimeter, int i_start)
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
			ret[curr] = split_delimeter;
	}
	return (ret);
}

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

// TODO: TESTS
bool	is_valid_env_var(char *key)
{
	int	i;

	if (NULL == key)
		return (false);
	i = 0;
	while (key[i])
	{
		if (1 != ft_isalnum(key[i] && '_' != key[i]))
			return (false);
		i++;
	}
	return (true);
}
