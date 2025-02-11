/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:01:06 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/03 15:30:25 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// malloc, free, NULL
# include <stdlib.h>
// input output system calls
# include <unistd.h>
// file options
# include <fcntl.h>

// compile time modifiable size for buffer
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

// linked list to hold file content
typedef struct s_str_list
{
	char			*content;
	struct s_str_list	*next;
}			t_str_list;

/*
 * @brief Return a single line form a file fd
 *
 * @param fd file desriptor of a file to read from
 * @return Content of a single line from fd (including the \n character) or
 * NULL on error or if there is nothing left to be read
 */
char	*get_next_line(int fd);
//void	alloc_list(t_list **list, int fd);
int		found_nl(t_str_list *list);
//void	list_append(t_list **list, char *buf);
//char	*get_line(t_list *list);
int		len_to_nl(t_str_list *list);
void	copy_content_to_nl(t_str_list *list, char *line);
t_str_list	*ft_str_lstlast(t_str_list *lst);
//void	clear_list_till_nl(t_list **list);
void	dealloc_list(t_str_list **list, t_str_list *clean_node, char *buf);

#endif
