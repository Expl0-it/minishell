/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:44:20 by codespace         #+#    #+#             */
/*   Updated: 2024/12/10 13:02:42 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (NULL == getcwd(cwd, PATH_MAX))
	{
		perror("minishell pwd");
		return (EXIT_FAILURE);
	}
	return (printf("%s\n", cwd), EXIT_SUCCESS);
}
