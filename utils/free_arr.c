#include "minishell.h"

void	free_arr(char **arr, int to_be_freed)
{
	int	i;

	i = -1;
	if (-1 == to_be_freed)
		while (NULL != arr[++i])
			free(arr[i]);
	else
		while (++i < to_be_freed)
			if (NULL != arr[i])
				free(arr[i]);
	free(arr);
}

// NOTE: free the array, if to_be_freed provided free n elements only
void	free_2d_arr(char ***arr, int to_be_freed)
{
	int	i;

	i = -1;
	if (-1 == to_be_freed)
		while (arr[++i])
			free_arr(arr[i], -1);
	else
		while (++i < to_be_freed)
			if (arr[i])
				free_arr(arr[i], -1);
	free(arr);
}
