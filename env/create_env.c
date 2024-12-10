/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:03:51 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/10 13:03:53 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_env_node(char **split)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (NULL == new_node || NULL == split[0])
		return (NULL);
	new_node->key = ft_strdup(split[0]);
	if (NULL == split[1])
		new_node->val = ft_strdup("");
	else if (NULL == split[2])
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

bool	create_env_var(t_env *env, char *env_literal)
{
	t_env	*new_node;
	t_env	*last_node;
	t_env	*overwrite;
	char	**split;

	split = ft_split(env_literal, '=');
	if (false == is_valid_env_var(split))
		return (free_str_arr(split, -1), false);
	overwrite = get_env_node(env, split[0]);
	if (NULL != overwrite)
		overwrite_env_var(overwrite, split);
	new_node = new_env_node(split);
	if (NULL == new_node)
		return (free_str_arr(split, -1), false);
	last_node = get_env_last_node(env);
	if (NULL == last_node)
		env = new_node;
	else
		last_node->next = new_node;
	return (free_str_arr(split, -1), true);
}
