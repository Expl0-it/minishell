/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:58:06 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/09 11:58:07 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(char **args, t_data *data)
{
	char	**to_export;
	int		i;

	i = 0;
	to_export = ft_split(args[1], ' ');
	while (to_export[i])
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
}
