#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef PATH_LEN
# define PATH_MAX 4096
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <bits/waitflags.h>
# include <dirent.h>
# include <errno.h>
# include <stdbool.h>
# include <limits.h>
# include <stdint.h>
# include "libft/libft.h"

# define ERR_EXIT_MANY_ARGS "minishell: exit: too many arguments "

// NOTE: a struct to contain enviromental variables where 'key'='value' (type export in bash to see)
typedef struct	s_env
{
	char		*key;
	char		*val;
	struct s_env	*next;
}   t_env;

typedef struct s_data
{
    char    **argv;
    char    *flags;
    char    *cmd;
	t_env	*env;
}   t_data;

// NOTE: basically that is how I would like parsing for piping to be done, we would do an array of those structs for every pipe
typedef struct s_pipes
{
	char	**cmd; // cmd + arg (like: [ls, -R -la, NULL] or [echo, -n, NULL] or [pwd, NULL])
	char	*limiter; // when using heredoc: << limiter || else NULL
	int		infd; // when redirecting input < infile
	int		outfd; // when redirecting output > outfile
	bool	here_doc; // do we use heredoc (input redirection "<<")
	bool	invalid_infile; // does the infile exist and do we have premissions to it?
	bool	append; // do we use replace ">" or append ">>" file's contents with output redirection
}			t_pipes;

typedef struct s_shell
{
	uint8_t	exit_code;
	t_env	*env;
}		t_shell;

// utils
// free_arr.c
void	free_str_arr(char **arr, int to_be_freed);
void	free_2d_str_arr(char ***arr, int to_be_freed);

// builtins
int	ft_env(t_shell *shell);
int	ft_pwd(void);
int	ft_echo(char **args);
int	ft_exit(char **args, t_shell *shell);

// init_env.c
int		init_env(t_data *data, char **envp); //changed to t_data *data

// env
t_env	*new_env_node(char **split);
int		init_env(t_data *data, char **envp);


// utils_env.c
char	*concat_split(char **split, char split_delimeter, int i_start);
t_env	*get_env_node(t_env *env, char *key);
t_env	*get_env_last_node(t_env *env);
int		get_env_size(t_env *env);
bool	is_valid_env_var(char *key);
void	free_str_arr(char **arr, int to_be_freed);

// parser
void	parse_input(t_data *data, char *input);
void    parse_env(t_data *data);

#endif
