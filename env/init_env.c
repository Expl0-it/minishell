/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:03:29 by mamichal          #+#    #+#             */
/*   Updated: 2025/01/05 21:31:14 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env *new_env(char *envp)
{
    t_env   *env;

    env = malloc(sizeof(t_env));
    if (!env)
    {
        printf("error: malloc failed\n");
        return (NULL);
    }
    env->key = ft_strndup(envp, ft_strchr(envp, '=') - envp);
    env->val = ft_strndup(ft_strchr(envp, '=') + 1, ft_strlen(ft_strchr(envp, '=') + 1));
    if (NULL == env->key || NULL == env->val)
    {
		free_env_var(env);
		printf("error: malloc failed\n");
		return (NULL);
    }
    env->next = NULL;
    return (env);
}

int init_env(t_data *data, char **envp)
{
    t_env   *current;
    short   i;

    i = 0;
    while (envp[i])
    {
        if (!i)
        {
            data->env = new_env(envp[i]);
            if (NULL == data->env)
                return (EXIT_FAILURE);
            current = data->env;
        }
        else
        {
            current->next = new_env(envp[i]);
            if (NULL == current->next)
                return (EXIT_FAILURE);
            current = current->next;
        }
        i++;
    }
    // change it later to so it doesnt always return 0 // NOTE: added those for you as well as the NULL checks above :DD
    return (EXIT_SUCCESS);
}
