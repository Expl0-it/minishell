/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:16:29 by mamichal          #+#    #+#             */
/*   Updated: 2025/01/04 21:03:04 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_paths(char *p1, char *p2)
{
	char	*slash_path;
	char	*full_path;

	if (!p2 || !p1)
		return (NULL);
	if (!ft_strncmp(p1, "/", 1))
	{
		if (p2[0] == '/')
			return (ft_strjoin(p1, p2));
		else
		{
			slash_path = ft_strjoin(p1, "/");
			full_path = ft_strjoin(slash_path, p2);
			free(slash_path);
			return (full_path);
		}
	}
	else
	{
		if (p2[0] == '/')
			return (ft_strjoin(p1, p2 + 1));
		else
			return (ft_strjoin(p1, p2));
	}
}

static bool	bin_is_executable(struct stat bin_stat)
{
	if ((bin_stat.st_mode > 0) && (S_IEXEC & bin_stat.st_mode) && S_ISREG(bin_stat.st_mode))
	{
		if (bin_stat.st_mode & S_IXUSR)
			return (true);
		else
			ft_putendl_fd("file is not executable", 2);
	}
	else
		ft_putendl_fd("file not found", 2);
	return (false);
}

char	*find_valid_bin_path(char *bin_name, char **split)
{
	struct stat	bin_stat;
	int			i;
	char		*bin_path;

	i = 0;
	while (NULL != split[i])
	{
		bin_path = join_paths(split[i], bin_name);
		if (NULL == bin_path)
			return (NULL);
		if (lstat(bin_path, &bin_stat) != -1)
		{
			if (bin_is_executable(bin_stat))
				return (bin_path);
		}
		else
			free(bin_path);
		i++;
	}
	return (NULL);
}
