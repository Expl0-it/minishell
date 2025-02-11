/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:01:01 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/03 15:31:05 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	found_nl(t_str_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_str_list	*ft_str_lstlast(t_str_list *lst)
{
	if (NULL == lst)
		return (NULL);
	while (NULL != lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	len_to_nl(t_str_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	copy_content_to_nl(t_str_list *list, char *line)
{
	int	i_line;
	int	i_content;

	if (NULL == list || NULL == line)
		return ;
	i_line = 0;
	while (list)
	{
		i_content = 0;
		while (list->content[i_content])
		{
			if (list->content[i_content] == '\n')
			{
				line[i_line++] = '\n';
				line[i_line] = 0;
				return ;
			}
			line[i_line++] = list->content[i_content++];
		}
		list = list->next;
	}
	line[i_line] = 0;
}

void	dealloc_list(t_str_list **list, t_str_list *clean_node, char *buf)
{
	t_str_list	*tmp;

	if (NULL != clean_node)
		clean_node->next = NULL;
	if (NULL == list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
