/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:36:40 by mamichal          #+#    #+#             */
/*   Updated: 2024/07/01 19:14:20 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

//file operation modes # include <fcntl.h> 

//first

/** @brief Fill memory with a constant byte.
 * 
 * The memset() function fills the first n bytes of the memory area
 * pointed to by s with the constant byte c.
 *
 * 	@param s pointer to a memory area to fill
 * 	@param c character to fill the memory area with
 * 	@param n number of bytes to fill
 *  @return The memset() function returns a pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n);

/** @brief Write zero-valued bytes.
 *
 *  The bzero() function sets the first n bytes of the
 * 	area starting at s to zero (bytes containing aq\0aq).
 *
 *  @param s pointer to a starting memory
 * 	@param n number of bytes to write to
 *  @return Void
 */
void	ft_bzero(void *s, size_t n);

/** @brief Copy memory area. 
 * 
 * The memcpy() function copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap.
 *
 * 	@param dest memory area to copy to
 * 	@param src memory area to copy from
 * 	@param n maximal number of bytes to copy
 *  @return The memcpy() function returns a pointer to dest
 *  memory area copied to)
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/** @brief Copy memory area.
 * 
 * 	Copies no more than n bytes from memory area src to memory area dest,
 * 	stopping when the character c is found.
 * 	If the memory areas overlap, the results are undefined.
 *
 * 	@param dest memory area to copy to
 * 	@param src memory area to copy from
 *  @param c int value of character to be found within memory
 * 	@param n maximal number of bytes to copy
 *  @return a pointer to the next character in dest after c, or NULL if not found
 */
//void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

/** @brief Duplicate a string.
 * 
 * 	The strdup() function returns a pointer 
 * 	to a new string which is a duplicate of the string s.
 *  Memory for the new string is obtained with malloc(3),
 *  and can be freed with free(3).
 *
 *  @param s string to duplicate
 *  @return a pointer to the duplicated string, or NULL
 */
char	*strdup(const char *s);

/** @brief Copy memory area. 
 * 
 * 	The memmove() function copies n bytes from memory area src
 * 	to memory area dest.
 * 	The memory areas may overlap: copying takes place as though the bytes in src
 * 	are first copied into a temporary array that does not overlap src or dest,
 *  and the bytes are then copied from the temporary array to dest.
 *
 * 	@param dest memory area to copy to
 * 	@param src memory area to copy from
 * 	@param n maximal number of bytes to copy
 *  @return The memmove() function returns a pointer to dest
 *  memory area copied to)
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/** @brief Scan memory for a character.
 * 
 * 	The memchr() function scans the initial n bytes of the memory area
 *  pointed to by s for the first instance
 * 	of c. Both c and the bytes of the memory area pointed
 *  to by s are interpreted as unsigned char.
 * 
 *  @param s pointer to a memory area to scan in
 * 	@param c value to scan for (unsigned char)
 * 	@param n maximal number of bytes to scan
 *  @return a pointer to the matching byte or NULL if the character not found 
 */
void	*ft_memchr(const void *s, int c, size_t n);

/** @brief Compare memory areas.
 * 
 * 	The memcmp() function compares the first n bytes
 *	(each interpreted as unsigned char)
 *  of the memory areas s1 and s2.
 * 
 *  @param s1 first memory area to compare
 * 	@param s2 second memory area to compare
 * 	@param n maximal number of bytes to compare
 *  @return integer less than, equal to, or greater than zero
 *  if the first n bytes of s1 is found
 *  respectively, to be less than, to match,
 *  or be greater than the first n bytes of s2
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/** @brief Calculate the length of a string.
 * 
 * 	The strlen() function calculates the length of the string s,
 *  excluding the terminating null byte ('\0').
 *
 *  @param str the string to measure
 *  @return the number of bytes in the string s
 */
size_t	ft_strlen(char const *str);

/** @brief Size-bounded string copying.
 * 
 * 	The strlcpy() function copies up to size - 1 characters
 *  from the NUL-terminated string src to dst, NUL-terminating the result.
 *
 *  @param dst the prefix string
 * 	@param src the suffix string
 * 	@param size the (maximal numer of bytes - 1) to copy from src to dst
 *  @return the length of src
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/** @brief Size-bounded string concatenation.
 * 
 * 	The strlcat() function appends the NUL-terminated string src
 *  to the end of dst. It will append at most
 *  size - strlen(dst) - 1 bytes, NUL-terminating the result.
 *
 *  @param dst the prefix string
 * 	@param src the suffix string
 * 	@param size the (maximal numer of bytes - 1) to copy from src to dst
 *  @return the initial length of dst plus the length of src
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/** @brief Locate character in string.
 * 
 * 	The strchr() function returns a pointer to the 
 *	first occurrence of the character c in the string s.
 * 	The terminating null byte is considered part of the string,
 *  so that if c is specified as '\0', these
 * 	functions return a pointer to the terminator.
 * 
 *  @param s string to scan in
 * 	@param c character to scan for (unsigned char)
 *  @return pointer to the matched character or NULL if not found
 */
char	*ft_strchr(const char *s, int c);

/** @brief Locate character in reversed string.
 * 
 * 	Returns a pointer to the last
 *  occurrence of the character c in the string s.
 * 	The terminating null byte is considered part of the string,
 *  so that if c is specified as '\0', these
 * 	functions return a pointer to the terminator.
 * 
 *  @param s string to scan in
 * 	@param c character to scan for (unsigned char)
 *  @return pointer to the matched character or NULL if not found
 */
char	*ft_strrchr(const char *s, int c);

/** @brief Locate a substring.
 * 
 * 	The strnstr() function finds the first occurrence
 *  of the substring needle in the string haystack.
 *  The terminating null bytes ('\0') are not compared.
 * 
 * 	@param haystack a string to scan
 * 	@param needle a string to find
 *  @return pointer to the beginning of the substring, or NULL if not found
 */
//char	*ft_strstr(const char *haystack, const char *needle);

/** @brief Locate a substrin.
 * 
 * 	Finds the first occurrence
 *  of the substring needle in the string haystack.
 *  The terminating null bytes ('\0') are not compared.
 * 	Scans at most n bytes.
 * 
 * 	@param haystack a string to scan
 * 	@param needle a string to find
 * 	@param n maximal number of bytes to scan
 *  @return pointer to the beginning of the substring, or NULL if not found
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/** @brief Compare two strings.
 * 
 * 	Compares the two strings s1 and s2. It returns an integer
 *  less than, equal to, or greater than zero if s1 is found,
 *  respectively, to be less than, to match, or be greater than s2.
 * 
 * 	@param s1 first string to compare
 * 	@param s2 second string to compare
 *  @return integer less than, equal to, or greater than zero 
 */
//int		ft_strcmp(char *s1, char *s2);

/** @brief Compare two strings.
 * 
 * 	Compares the two strings s1 and s2. It returns an integer
 *  less than, equal to, or greater than zero if s1 is found,
 *  respectively, to be less than, to match, or be greater than s2.
 *  It only compares the first (at most) n bytes of s1 and s2.
 * 
 * 	@param s1 first string to compare
 * 	@param s2 second string to compare
 * 	@param n maximum number of bytes to compare
 *  @return integer less than, equal to, or greater than zero 
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/** @brief Convert a string to an integer.
 *
 *  The atoi() function converts the initial portion of the string
 *  pointed to by nptr to int.
 *
 *  @param nptr pointer to a string to be converted.
 *  @return Int converted from a string.
 *	@bug overflow not taken care of
 */
int		ft_atoi(const char *nptr);

/** @brief Checks for an alphabetic character.
 *
 * 	Check whether c, which must have the value of an unsigned char
 *  falls into a certain character class according to the current locale.
 *
 *  @param c int value of character in character encoding (unsigned char)
 *  @return 1 if true, 0 if false
 */
int		ft_isalpha(int c);

/** @brief Checks for a digit (0 through 9).
 *
 * 	Check whether c, which must have the value of an unsigned char
 *  falls into a certain character class according to the current locale.
 *
 *  @param c int value of character in character encoding (unsigned char)
 *  @return 1 if true, 0 if false
 */
int		ft_isdigit(int c);

/** @brief Checks for an alphanumeric character;
 *  it is equivalent to (isalpha(c) || isdigit(c)). \n \n
 *
 * 	Check whether c, which must have the value of an unsigned char
 *  falls into a certain character class according to the current locale.
 *
 *  @param c int value of character in character encoding (unsigned char)
 *  @return 1 if true, 0 if false
 */
int		ft_isalnum(int c);

/** @brief Checks if c is a 7-bit unsigned char from the ASCII character set.
 *
 * 	Check whether c, which must have the value of an unsigned char
 *  falls into a certain character class according to the current locale.
 *
 *  @param c int value of character in character encoding (unsigned char)
 *  @return 1 if true, 0 if false
 */
int		ft_isascii(int c);

/** @brief Checks for any printable character including space.
 *
 * 	Check whether c, which must have the value of an unsigned char
 *  falls into a certain character class according to the current locale.
 *
 *  @param c int value of character in character encoding (unsigned char)
 *  @return 1 if true, 0 if false
 */
int		ft_isprint(int c);

/** @brief Convert letter to upper case.
 * 
 * 	Converts the letter c to upper case, if possible.
 * 	If c is not an unsigned char value, or EOF,
 *  the behavior of these functions is undefined.
 * 
 * 	@param c letter to convert
 *  @return converted letter, or c if the conversion was not possible
 */
int		ft_toupper(int c);

/** @brief Convert letter to lower case.
 * 
 * 	Converts the letter c to lower case, if possible.
 * 	If c is not an unsigned char value, or EOF,
 *  the behavior of these functions is undefined.
 * 
 * 	@param c letter to convert
 *  @return converted letter, or c if the conversion was not possible
 */
int		ft_tolower(int c);

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
void	*ft_calloc(size_t nmemb, size_t size);

/** @brief Duplicate a string.
 * 
 * 	The strdup() function returns a pointer 
 * 	to a new string which is a duplicate of the string s.
 *  Memory for the new string is obtained with malloc(3),
 *  and can be freed with free(3).
 *
 *  @param s string to duplicate
 *  @return a pointer to the duplicated string, or NULL if no memory
 */
char	*ft_strdup(const char *s);

//second

/** @brief Allocate dynamic memory.
 * 
 * 	Allocates (with malloc(3)) and returns a “fresh” memory
 * 	area. The memory allocated is initialized to 0. If the allocation fails,
 *  the function returns NULL
 * 
 *  @param size the size of the memory that needs to be allocated
 *  @return the allocated memory area
 */
//void	*ft_memalloc(size_t size);

/** @brief Free memory area.
 * 
 * 	Takes as a parameter the address of a memory area that needs 
 *	to be freed with free(3), then puts the pointer to NULL
 *
 *  @param ap pointer’s address that needs its memory freed and set to NULL.
 *  @return Void
 */
//void	ft_memdel(void **ap);

/** @brief Allocate a string.
 * 
 * 	Allocates (with malloc(3)) and returns a “fresh” string
 *  ending with ’\0’. Each character of the string is initialized at
 * 	’\0’. If the allocation fails the function returns NULL.
 * 
 * 	@param size the size of the string to be allocated
 *  @return the string allocated and initialized to 0.
 */
//char	*ft_strnew(size_t size);

/** @brief Free memory area.
 * 
 * 	Takes as a parameter the address of a string that need to be
 * 	freed with free(3), then sets its pointer to NULL.
 *
 *  @param string’s address that needs to be freed
 *  @return Void
 */
//void	ft_strdel(char **as);

/** @brief Sets every character of the string to the value ’\0’.
 * 
 *  @param s the string that needs to be cleared
 *  @return pointer to the matched character or NULL not found
 */
//void	ft_strclr(char *s);

/** @brief Apply function to evry character
 *
 * Applies the function ’f’ on each character of
 * the string passed as argument, passing its index
 * as first argument. Each character is passed by
 * address to ’f’ to be modified if necessary.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/** @brief Allocate a modified string.
 * 
 * 	Applies the function ’f’ to each character of the
 * 	string ’s’ to create a new string (with malloc(3))
 * 	resulting from successive applications of ’f’.

 *
 *  @param s the reference string
 * 	@param f the function to apply to each character
 *  @return string created from the applications of ’f’ or NULL at fail
 */
//char	*ft_strmap(char const *s, char (*f)(char));

/** @brief Allocate a modified string.
 * 
 * 	Applies the function ’f’ to each character of the
 * 	string ’s’ to create a new string (with malloc(3))
 * 	resulting from successive applications of ’f’.
 *
 *  @param s the reference string
 * 	@param f the function to apply to each character
 *  @return string created from applications of ’f’ or NULL if fails
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/** @brief Allocate a substring.
 * 
 * 	Allocates (with malloc(3)) and returns a “fresh” substring
 * 	from the string given as argument. The substring begins at
 * 	indexstart and is of size len. If start and len aren’t refering
 *  to a valid substring, the behavior is undefined. If the
 * 	allocation fails, the function returns NULL.
 * 
 * 	@param s string from which create the substring
 * 	@param start starting index of the substring
 * 	@param len maximum size of the substring
 *  @return the allocated substring
 */
//char	*ft_strsub(char const *s, unsigned int start, size_t len);

/** @brief Concatanate strings.
 * 
 * 	Creates (with malloc(3)) and returns a “fresh” allocated
 * 	string ending with ’\0’,
 *  result of the concatenation of s1 and s2. If the allocation fails
 *  the function returns NULL.
 *
 *  @param s1 the prefix string
 * 	@param s2 the suffix string
 *  @return The allocated string result of the concatenation of the 2 strings
 */
char	*ft_strjoin(char const *s1, char const *s2);

/** @brief Trim start and end of a string.
 * 
 * 	Allocates (with malloc(3)) and returns a copy of
 * 	’s1’ with the characters specified in ’set’ removed
 * 	from the beginning and the end of the string.
 * 
 * 	@param s1 string to be trimmed
 * 	@param set reference set of characters to trim
 *  @return The trimmed string or NULL if the allocation fails
 */
char	*ft_strtrim(char const *s1, char const *set);

/** @brief Separate stirngs and put into the array
 * 
 * 	Allocates (with malloc(3)) and returns an array
 * 	of strings obtained by splitting ’s’ using the
 * 	character ’c’ as a delimiter. The array must be
 * 	ended by a NULL pointer
 * 
 * 	@param s The string to be split
 * 	@param c The delimiter character
 *  @return The array of new strings from the split or NULL
 */
char	**ft_split(char const *s, char c);

/** @brief Convert integer to string.
 * 
 * 	Allocates (with malloc(3)) and returns a string
 * 	representing the integer received as an argument.
 * 	Negative numbers must be handled
 * 
 * 	@param n the integer to convert
 *  @return The string representing the integer or NULL if the allocation fails
 */
char	*ft_itoa(int n);

/** @brief Put a character in file.
 * 
 * 	Outputs the character ’c’ to the given file
 * 	descriptor. \n	 	
 * 	STDFD:
 * 	0 => stdin;
 * 	1 => stdout;
 * 	2 => stderr;
 * 
 * 	@param c The character to output
 * 	@param fd The file descriptor on which to write
 *  @return Void.
 */
void	ft_putchar_fd(char c, int fd);

/** @brief Put a string in file.
 * 
 * 	Outputs the string 's' to the given file
 * 	descriptor.
 * 	STDFD:
 * 	0 => stdin;
 * 	1 => stdout;
 * 	2 => stderr;
 * 
 * 	@param s The string to output
 * 	@param fd The file descriptor on which to write
 *  @return Void.
 */
void	ft_putstr_fd(char *s, int fd);

/** @brief Put a string followed by new line in file.
 * 
 * 	Outputs the string ’s’ to the given file
 * 	descriptor, followed by a newline.
 * 	STDFD:
 * 	0 => stdin;
 * 	1 => stdout;
 * 	2 => stderr;
 * 
 * 	@param s The string to output
 * 	@param fd The file descriptor on which to write
 *  @return Void.
 */
void	ft_putendl_fd(char *s, int fd);

/** @brief Put a number in file.
 * 
 * 	Outputs the integer ’n’ to the given file
 * 	descriptor.
 * 	STDFD:
 * 	0 => stdin;
 * 	1 => stdout;
 * 	2 => stderr;
 * 
 * 	@param n The integer to output
 * 	@param fd The file descriptor on which to write
 *  @return Void.
 */
void	ft_putnbr_fd(int n, int fd);

/** @brief Allocate a substring.
 * 
 * 	Allocates (with malloc(3)) and returns a “fresh” substring
 * 	from the string given as argument. The substring begins at
 * 	indexstart and is of size len. If start and len aren’t refering
 *  to a valid substring, the behavior is undefined. If the
 * 	allocation fails, the function returns NULL.
 * 
 * 	@param s string from which create the substring
 * 	@param start starting index of the substring
 * 	@param len maximum size of the substring
 *  @return the allocated substring
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

//bonus

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

/*
 * @brief Create last node of the list
 *
 * Allocates (with malloc(3)) and returns a new node.
 * The member variable ’content’ is initialized with
 * the value of the parameter ’content’. The variable
 * ’next’ is initialized to NULL.
 *
 * @param content The content to create a node with
 * @return new node with content and next set to NULL
*/
t_list	*ft_lstnew(void *content);

/*
 * @brief Add node to the beginning of the list
 *
 * Adds the node ’element’ at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link
 * @param element The address of a pointer to the node to be added
 * @return new node with content and next set to NULL
*/
void	ft_lstadd_front(t_list **lst, t_list *element);

/*
 * @brief Count the length of the list 
 *
 * Counts the number of nodes in a list.
 *
 * @param lst The beginning of the list 
 * @return Length of the list
*/
int		ft_lstsize(t_list *lst);

/*
 * @brief Show last node of a list
 *
 * Returns the last node of the list
 *
 * @param lst The beginning of the list
 * @return Last node of the list
*/
t_list	*ft_lstlast(t_list *lst);

/*
 * @brief Add node to the end of the list
 *
 * Adds the node ’element’ at the end of the list.
 *
 * @param lst The address of a pointer to the first link
 * @param element The address of a pointer to the node to be added
 * @return Void
*/
void	ft_lstadd_back(t_list **lst, t_list *element);

/*
 * @brief Delate the node from the list
 *
 * Takes as a parameter a node and frees the memory of
 * the node’s content using the function ’del’ given
 * as a parameter and free the node. The memory of
 * ’next’ must not be freed
 *
 * @param lst The node to free
 * @param del address of the function deleting the conten
 * @return Void
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*));

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
void	ft_lstclear(t_list **lst, void (*del)(void*));

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
void	ft_lstiter(t_list *lst, void (*f)(void *));

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
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//additional

#endif
