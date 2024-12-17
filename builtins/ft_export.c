/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:58:06 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/17 13:29:08 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(t_data *data, char **args)
{
	char	**to_export;
	int		i;

	i = 0;
	to_export = ft_split(args[1], ' ');
	while (NULL != to_export && NULL != to_export[i])
	{
		if (false == create_env_var(data->env, to_export[i]))
		{
			ft_putstr_fd("minishell: export: `", STDERR_FILENO);
			ft_putstr_fd(to_export[i], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		}
		i++;
	}
	free_str_arr(to_export, -1);
	return (0);
}
