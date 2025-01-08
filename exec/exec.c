/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:49:26 by mamichal          #+#    #+#             */
/*   Updated: 2025/01/08 11:41:41 by mamichal         ###   ########.fr       */
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

static int	exec_bin(t_data *data, int i)
{
	char	*bin_path;
	pid_t	pid;
	int		res;

	bin_path = get_path(data, i);
	if (NULL == bin_path)
		return (-1);
	pid = fork();
	res = 0;
	if (0 == pid)
		res = execve(bin_path, data->pipes[i].cmd, NULL);
	else if (pid < 0)
	{
		free(bin_path);
		ft_putstr_fd("fork failed", 2);
		return (-1);
	}	
	wait(&res);
	free(bin_path);
	data->cmd_exit_code = res;
	return (res);
}

static void	fork_exec(t_data *data, int i)
{
	t_pipes	*cur_pipe;

	cur_pipe = &data->pipes[i];
	cur_pipe->pid = fork();
	if (-1 == cur_pipe->pid)
		err_exit(data, "fork failed", FORK_ERR);
	if (0 == cur_pipe->pid)
	{
		close_useless_pipes(data, i);
		handle_redirections(data, i);
		data->cmd_exit_code = exec_bin(data, i);
	}
}

void	execute(t_data *data)
{
	int	i;
	int	res;

	i = 0;
	open_pipes(data);
	while (data->pipes[i].cmd)
	{
		res = exec_builtin(data, i);
		data->pipes[i].pid = 0;
		if (-1 == res)
			fork_exec(data, i);
		else
			data->cmd_exit_code = res;
		i++;
	}
	close_pipes(data);
	// NOTE: assign to exit code
	// data->cmd_exit_code
}
