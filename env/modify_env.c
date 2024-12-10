/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:03:46 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/10 13:03:56 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	overwrite_env_var(t_env *overwrite, char **split)
{
	if (NULL == overwrite || NULL == split)
		return (false);
	free(overwrite->val);
	overwrite->val = NULL;
	if (NULL == split[1])
		overwrite->val = ft_strdup("");
	else if (NULL == split[2])
		overwrite->val = ft_strdup(split[1]);
	else
		overwrite->val = concat_split(split, '=', 1);
	if (NULL == overwrite->val)
		return (false);
	else
		return (true);
}

bool	set_env_var(t_env *env, char *key, char *val)
{
	int	len;

	if (NULL == key)
		return (false);
	len = ft_strlen(key);
	while (NULL != env)
	{
		if (0 == ft_strncmp(key, env->key, len + 1))
		{
			free(env->val);
			if (NULL == val)
				env->val = ft_strdup("");
			else
				env->val = ft_strdup(val);
			if (NULL == env->val)
				return (false);
			return (true);
		}
		env = env->next;
	}
	return (false);
}

bool	rm_env_var(t_env *env, char *key)
{
	t_env	*prev;
	t_env	*curr;
	int		len;

	curr = env;
	prev = NULL;
	if (NULL == key)
		return (false);
	len = ft_strlen(key);
	while (NULL != curr)
	{
		if (0 == ft_strncmp(curr->key, key, len + 1))
		{
			if (NULL != prev)
				prev->next = curr->next;
			else
				env = curr->next;
			free_env_var(curr);
			return (true);
		}
		prev = curr;
		curr = curr->next;
	}
	return (false);
}
