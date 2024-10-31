/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:49:04 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:52:29 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/** @brief Separate stirngs and put into the array
 * 
 * 	Allocates (with malloc(3)) and returns an array
 * 	of strings obtained by splitting ’s’ using the
 * 	character ’c’ as a delimiter. The array must be
 * 	ended by a NULL pointer
 * 
 * 	@param s The string to be split
 * 	@param c The delimiter character
 *  @return The array of new strings resulting from the split or NULL
 */

// Count all the tokens (words) in the string
static size_t	count_tokens(char const *s, char c);

// Copy strings to correct position, return 0 if mallocs worked otherwise 1
static int		fill_tokens(char **words, char const *s, char c);

// malloc space for a word, free all the words if error on allocation
static int		safe_malloc(char **words, int position, size_t buffer);

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	tokens;

	if (NULL == s)
		return (NULL);
	tokens = count_tokens(s, c);
	words = (char **)malloc((tokens + 1) * sizeof(char *));
	if (NULL == words)
		return (NULL);
	words[tokens] = NULL;
	if (fill_tokens(words, s, c))
		return (NULL);
	return (words);
}

// tested, works properly
static size_t	count_tokens(char const *s, char c)
{
	int	count;
	int	trigger;
	int	i;

	count = 0;
	trigger = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (s[i] == c)
			trigger = 0;
		i++;
	}
	return (count);
}

static int	fill_tokens(char **words, char const *s, char c)
{
	size_t	len;
	int		position;

	position = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_malloc(words, position, len + 1))
				return (1);
			ft_strlcpy(words[position], s - len, len + 1);
			position++;
		}
	}
	return (0);
}

static int	safe_malloc(char **words, int position, size_t buffer)
{
	int	i;

	i = 0;
	words[position] = (char *)malloc(buffer);
	if (NULL == words[position])
	{
		while (i < position)
		{
			free(words[i]);
			i++;
		}
		free(words);
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>

int main (void)
{
	char **strings = ft_split("", 0);
// 	printf("%s\n", strings[0]);
//	printf("%s\n", strings[1]);
//	printf("%s\n", strings[2]);
//	printf("%s\n", strings[3]);
//	printf("%s\n", strings[4]);
//	printf("%s", strings[5]);
//	printf("%s\n", strings[5]);
//	printf("%s\n", strings[6]);
//	printf("%s\n", strings[7]);
//	printf("%s", strings[8]);

	free(strings);
	return (0);
}
*/
