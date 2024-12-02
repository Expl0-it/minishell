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

t_env	*get_last_node(t_env *env)
{
	t_env	*last_node;

	last_node = env;
	while (NULL != last_node->next)
		last_node = last_node->next;
	return (last_node);
}
