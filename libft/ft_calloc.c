/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:48:15 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:58:57 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Allocate dynamic memory.
 *
 *  The calloc() function allocates memory for an
 *  array of nmemb elements of size bytes each and
 *  returns a pointer to the allocated memory.
 *  The memory is set to zero. If nmemb or size is 0,
 *  then calloc() returns either NULL, or a unique pointer
 *  value that can later be successfully passed to free().
 *
 *  @param nmemb number of elements to allocate
 * 	@param size size of each element to allocate
 *  @return pointer to the allocated memory, NULL on error or if any params = 0
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p_memory;
	size_t	memory_size;

	memory_size = nmemb * size;
	p_memory = malloc(memory_size);
	if (p_memory == NULL)
		return (NULL);
	ft_bzero(p_memory, memory_size);
	return (p_memory);
}

/*
#include <stdio.h>
int	main(void)
{
	int	*a = (int *)ft_calloc(2, sizeof(int));
	printf("start: %p\n", a);
	return (0);
}
*/
