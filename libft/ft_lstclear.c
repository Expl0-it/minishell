/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:53:31 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:42:07 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
 * @brief Delate the list starting with given node
 *
 * Deletes and frees the given node and every
 * successor of that node, using the function ’del’
 * and free(3). Finally, the pointer to the list
 * must be set to NULL.
 *
 * @param lst The address of a pointer to a node
 * @param del address of the function deleting the content
 * @return Void
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (NULL == lst || NULL == del || *lst == NULL)
		return ;
	while (lst && (*lst))
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

/*
#include <stdio.h>
static	void del(void *content)
{
	if (content)
		return ;
	return ;
}

int main(void)
{
	t_list	*node1 = ft_lstnew("123");
	t_list	*node2 = ft_lstnew("abc");
	if (NULL == node1)
		return (1);
	ft_lstadd_front(&node2, node1);
	printf("%s, %p\n", (char *)node1->content, node1);
	ft_lstclear(&node1, del);
	printf("%p", node1);
	return EXIT_SUCCESS;
}
*/
