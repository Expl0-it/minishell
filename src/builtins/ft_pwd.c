/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:27:19 by mamichal          #+#    #+#             */
/*   Updated: 2024/11/12 16:03:41 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ft_pwd(void)
{
	// TODO: TESTS
	char cwd[PATH_MAX];
	if (NULL == getcwd(cwd, PATH_MAX))
	{
		perror("minishell pwd");
		return (EXIT_FAILURE);
	}
	return (printf("%s\n", cwd), EXIT_SUCCESS);
}
