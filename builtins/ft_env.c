/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:36:29 by mamichal          #+#    #+#             */
/*   Updated: 2024/11/25 13:39:34 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_shell *shell)
{
	t_env	*env;

	env = shell->env;
	if (NULL == env)
		return (EXIT_FAILURE);
	while (NULL != env)
	{
		printf("%s", env->key);
		printf("=");
		printf("%s", env->val);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}
