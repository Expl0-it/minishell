/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:53:31 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/17 16:36:24 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
 * @brief Add node to the beginning of the list
 *
 * Adds the node ’new’ at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link
 * @param new The address of a pointer to the node to be added
 * @return Void
*/
void	ft_lstadd_front(t_list **lst, t_list *element)
{
	if (NULL != lst && NULL != element)
	{
		if (NULL != *lst)
			element->next = *lst;
		*lst = element;
	}
}

/*
#include <stdio.h>
int main(void)
{
	t_list	*node1 = ft_lstnew("123");
	t_list	*node2 = ft_lstnew("abc");
	if (NULL == node1 || NULL == node2)
	{
		return (1);
	}
	ft_lstadd_front(&node2, node1);
	printf("%p\n", node1->next);
	printf("%p", node2->next);
	return EXIT_SUCCESS;
}
*/
