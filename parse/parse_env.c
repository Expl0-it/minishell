/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:07:34 by codespace         #+#    #+#             */
/*   Updated: 2024/12/03 10:48:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    parse_env(t_data *data)
{
    t_env    *tmp;
    int     i;
    int     j;
    int     k;
    
    i = 0;
    tmp = data->env;
    while (data->argv[i])
    {
        if (ft_strchr(data->argv[i], '$'))
        {
            k = 0;
            while (data->argv[i][k] == '$')
                k++;
            while (data->env->key)
            {
                if (ft_strncmp(data->env->key, &data->argv[i][k], ft_strlen(data->env->key)) == 0)
                {
                    j = 0;
                    while (data->env->val[j])
                    {
                        data->argv[i][j] = data->env->val[j];
                        j++;
                    }
                    data->argv[i][j] = '\0';
                }
                data->env = data->env->next;
            }
            data->env = tmp;
        }
        i++;
    }
    i = 0;
    while (data->argv[i] != NULL)
	{
		printf("data->argv[%d] = %s\n", i, data->argv[i]);
		i++;
	}
}
