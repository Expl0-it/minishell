/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:29:46 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/09 12:25:08 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_data *data, char **args)
{
	char	**to_unset;
	int		i;

	i = 0;
	to_unset = ft_split(args[1], ' ');
	while (to_unset[i])
	{
		rm_env_var(data->env, to_unset[i]);
		i++;
	}
	free_str_arr(to_unset, -1);
}
