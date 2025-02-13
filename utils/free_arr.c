/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:04:16 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/13 13:14:50 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str_arr(char **arr, int to_be_freed)
{
	int	i;

	i = 0;
	if (to_be_freed < 0)
	{
		while (NULL != arr[i])
		{
			free(arr[i]);
			arr[i++] = NULL;
		}
	}
	else
	{
		while (i < to_be_freed)
		{
			if (NULL != arr[i])
			{
				free(arr[i]);
				arr[i++] = NULL;
			}
		}
	}
	free(arr);
	arr = NULL;
}

// NOTE: free the array, if to_be_freed provided free n elements only
void	free_2d_str_arr(char ***arr, int to_be_freed)
{
	int	i;

	i = 0;
	if (to_be_freed < 0)
	{
		while (arr[i])
		{
			free_str_arr(arr[i], -1);
			arr[i++] = NULL;
		}
	}
	else
	{
		while (i < to_be_freed)
		{
			if (arr[i])
			{
				free_str_arr(arr[i], -1);
				arr[i++] = NULL;
			}
		}
	}
	free(arr);
	arr = NULL;
}
