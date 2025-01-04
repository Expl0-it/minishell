/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:15:26 by mamichal          #+#    #+#             */
/*   Updated: 2025/01/04 19:38:00 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_absolute_path(t_data *data, char *cmd_path)
{
	char	*abs_path;
	char	*cwd;
	char	*tmp;

	if ('.' == cmd_path[0])
	{
		cwd = get_env_val(data->env, "PWD");
		tmp = ft_substr(cmd_path, 1, ft_strlen(cmd_path) - 1);
		abs_path = ft_strjoin(cwd, tmp);
		free(tmp);
	}
	else
		abs_path = ft_strdup(cmd_path);
	return (abs_path);
}

static char	*get_bin_path(t_data *data, char *bin_name)
{
	char	*bin_path;
	char	*tmp;
	char	**split;

	tmp = get_env_val(data->env, "PATH");
	if (NULL == tmp)
		return (NULL);
	split = ft_split(tmp, ':');
	if (NULL == split)
		return (NULL);
	bin_path = find_valid_bin_path(bin_name, split);
	free_str_arr(split, -1);
	if (NULL == bin_path)
		return (NULL);
	return (bin_path);
}
