/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:00:55 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/03 15:30:49 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static void	list_append(t_str_list **list, char *buf)
{
	t_str_list	*last_node;
	t_str_list	*new_node;

	last_node = ft_str_lstlast(*list);
	new_node = (t_str_list *)malloc(sizeof(t_str_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = (char *)buf;
	new_node->next = NULL;
}

static void	alloc_list(t_str_list **list, int fd)
{
	int		bytes_read;
	char	*buf;

	while (!found_nl(*list))
	{
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (NULL == buf)
			return ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buf);
			return ;
		}
		buf[bytes_read] = 0;
		list_append(list, buf);
	}
}

static char	*get_line(t_str_list *list)
{
	int		len;
	char	*line;

	if (NULL == list)
		return (NULL);
	len = len_to_nl(list);
	line = (char *)malloc((len + 1) * sizeof(char));
	if (NULL == line)
		return (NULL);
	copy_content_to_nl(list, line);
	return (line);
}

static void	clear_list_till_nl(t_str_list **list)
{
	t_str_list	*last_node;
	t_str_list	*clean_node;
	int		i_con;
	int		i_buf;
	char	*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (NULL == buf)
		return ;
	clean_node = (t_str_list *)malloc(sizeof(t_str_list));
	if (NULL == clean_node)
	{
		free(buf);
		return ;
	}
	last_node = ft_str_lstlast(*list);
	i_con = 0;
	i_buf = 0;
	while (last_node->content[i_con] && last_node->content[i_con] != '\n')
		i_con++;
	while (last_node->content[i_con] && last_node->content[++i_con])
		buf[i_buf++] = last_node->content[i_con];
	buf[i_buf] = 0;
	clean_node->content = buf;
	dealloc_list(list, clean_node, buf);
}

char	*get_next_line(int fd)
{
	static t_str_list	*list = NULL;
	char			*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	alloc_list(&list, fd);
	if (NULL == list)
		return (NULL);
	next_line = get_line(list);
	clear_list_till_nl(&list);
	return (next_line);
}
