/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:includes/execute.h
/*   Created: 2024/11/04 20:00:20 by mamichal          #+#    #+#             */
/*   Updated: 2024/11/12 15:38:58 by mamichal         ###   ########.fr       */
=======
/*   Created: 2024/11/10 20:51:01 by codespace         #+#    #+#             */
/*   Updated: 2024/11/12 20:28:06 by codespace        ###   ########.fr       */
>>>>>>> b6e9c34 (reorganized):main.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD:includes/execute.h
# include "minishell.h"

# ifndef PATH_LEN
#	define PATH_MAX 4096
# endif

// builtins:
int	ft_echo(char **args);
int	ft_pwd(void);

#endif
=======
int     main(int argc, char **argv, char **envp)
{
    char    *line;
    
    while (1)
    {
        line = readline("minishell$ ");
    }
}
>>>>>>> b6e9c34 (reorganized):main.c
