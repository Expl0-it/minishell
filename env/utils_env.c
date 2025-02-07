/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:03:39 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/10 13:03:56 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// NOTE: used in case when enviromental variable has '=' inside it
char	*concat_split(char **split, char split_delimeter, int i_start)
{
	int		i;
	int		len;
	int		curr;
	char	*ret;

	if (NULL == split)
		return (NULL);
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

bool	is_valid_env_var(char **split)
{
	int		i;
	char	*key;

	if (NULL == split || NULL == split[0])
		return (false);
	key = split[0];
	i = 0;
	while (0 != key[i])
	{
		if (0 == ft_isalnum(key[i]) && '_' != key[i])
			return (false);
		i++;
	}
	return (true);
}

void	free_env_var(t_env *env_var)
{
	free(env_var->key);
	free(env_var->val);
	free(env_var);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (NULL != env)
	{
		tmp = env;
		env = env->next;
		free_env_var(tmp);
	}
	env = NULL;
}
