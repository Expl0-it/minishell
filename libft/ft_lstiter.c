/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:53:31 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:42:15 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
 * @brief Modify the content of each node
 *
 * Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node
 *
 * @param lst The address of a pointer to a node
 * @param f The address of function iterating on the list
 * @return Void
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (NULL == lst || NULL == f)
		return ;
	while (NULL != lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*

// Won't work, node.content is read-only memory
void	f(void *content)
{
	int		i;
	char	*p_content;

	p_content = (char *)content;
	i = 0;
	while (p_content[i])
	{
		p_content[i] = ft_toupper(p_content[i]);
		i++;
	}
}

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
	ft_lstiter(node1, f);
	printf("%s\n", (char *)node1->content);
	printf("%s", (char *)node2->content);
	return EXIT_SUCCESS;
}
*/
