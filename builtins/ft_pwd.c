/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:27:19 by mamichal          #+#    #+#             */
<<<<<<< HEAD:src/builtins/ft_pwd.c
/*   Updated: 2024/11/12 16:03:41 by mamichal         ###   ########.fr       */
=======
/*   Updated: 2024/11/12 20:30:47 by codespace        ###   ########.fr       */
>>>>>>> b6e9c34 (reorganized):builtins/ft_pwd.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
