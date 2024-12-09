/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:20:14 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/09 13:46:52 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	update_env_pwd(t_data *data, char *old_pwd)
{
	char	*new_pwd;

	new_pwd = getcwd(NULL, 0);
	if (NULL == new_pwd)
		return (free(old_pwd), false);
	if (false == set_env_var(data->env, "OLDPWD", old_pwd))
		return (free(old_pwd), free(new_pwd), false);
	if (false == set_env_var(data->env, "PWD", new_pwd))
		return (free(old_pwd), free(new_pwd), false);
	free(old_pwd);
	free(new_pwd);
	return (true);

}

int	ft_cd(t_data *data, char **args)
{
	// NOTE: TESTS
	char	*new_pwd;
	char	*old_pwd;

	new_pwd = args[1];
	if (NULL != get_env_val(data->env, "PWD"))
		old_pwd = ft_strdup(get_env_val(data->env, "PWD"));
	else
		old_pwd = getcwd(NULL, 0);
	if (0 != chdir(new_pwd))
	{
		ft_putstr_fd("minishell: cd: can't cd to ", STDERR_FILENO);
		ft_putendl_fd(new_pwd, STDERR_FILENO);
		return (free(old_pwd), EXIT_FAILURE);
	}
	return (update_env_pwd(data, old_pwd));
}
