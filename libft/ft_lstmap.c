/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:53:31 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:42:18 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
 * @brief Create new, modified list
 *
 * Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node. Creates a new
 * list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to
 * delete the content of a node if needed.
 *
 * @param lst The address of a pointer to a node
 * @param f address of the function iterating on the list
 * @param del address of the function used to delete the content of a node
 * @return The newly created list
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*mapped_content;

	if (NULL == lst || NULL == f || NULL == del)
		return (NULL);
	new_lst = NULL;
	while (NULL != lst)
	{
		mapped_content = f(lst->content);
		node = ft_lstnew(mapped_content);
		if (NULL == node)
		{
			del(mapped_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
/*

// Won't work, node.content is read-only memory
static void*	f(void *content)
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
	return ((void *)content);
}

static	void del(void *content)
{
	if (content)
		return ;
	return ;
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
	t_list	*new = ft_lstmap(node1, &f, del);
	printf("%s\n", (char *)new->content);
	new = new->next;
	printf("%s", (char *)(new->content));
	return EXIT_SUCCESS;
}
*/
