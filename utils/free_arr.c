/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:04:16 by mamichal          #+#    #+#             */
/*   Updated: 2024/12/10 13:04:17 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str_arr(char **arr, int to_be_freed)
{
	int	i;

	i = -1;
	if (to_be_freed < 0)
		while (NULL != arr[++i])
			free(arr[i]);
	else
		while (++i < to_be_freed)
			if (NULL != arr[i])
				free(arr[i]);
	free(arr);
}

// NOTE: free the array, if to_be_freed provided free n elements only
void	free_2d_str_arr(char ***arr, int to_be_freed)
{
	int	i;

	i = -1;
	if (to_be_freed < 0)
		while (arr[++i])
			free_str_arr(arr[i], -1);
	else
		while (++i < to_be_freed)
			if (arr[i])
				free_str_arr(arr[i], -1);
	free(arr);
}
