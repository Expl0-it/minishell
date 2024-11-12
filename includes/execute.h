/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:00:20 by mamichal          #+#    #+#             */
/*   Updated: 2024/11/12 13:19:05 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

# ifndef PATH_LEN
#	define PATH_MAX 4096
# endif

// builtins:
int	ft_echo(const char **args);
int	ft_pwd(void);

#endif
