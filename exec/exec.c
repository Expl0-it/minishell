/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:49:26 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/17 13:49:18 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_builtin(t_data *data, int i)
{
	char	**args;
	int		len;

	args = data->pipes[i].cmd;
	if (NULL == args || NULL == args[0])
		return (-1); // NOTE: for safety but dunno if I shall do something else
	len = ft_strlen(args[0]);
	if (0 == ft_strncmp("echo", args[0], len + 1))
		return (ft_echo(args));
	if (0 == ft_strncmp("cd", args[0], len + 1))
		return (ft_cd(data, args));
	if (0 == ft_strncmp("pwd", args[0], len + 1))
		return (ft_pwd());
	if (0 == ft_strncmp("export", args[0], len + 1))
		return (ft_export(data, args));
	if (0 == ft_strncmp("unset", args[0], len + 1))
		return (ft_unset(data, args));
	if (0 == ft_strncmp("env", args[0], len + 1))
		return (ft_env(data));
	if (0 == ft_strncmp("exit", args[0], len + 1))
		return (ft_exit(data, args));
	return (-1);
}

void	execute(t_data *data)
{
	int	i;
	int	res;
	(void)res; // NOTE: temp, just to compile

	i = 0;
	open_pipes(data);
	while (data->pipes[i].cmd)
	{
		res = exec_builtin(data, i);
		// TODO:
		i++;
	}
	close_pipes(data);
}
