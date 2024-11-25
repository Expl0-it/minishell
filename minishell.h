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
# include "../libft/libft.h"

# define ERR_EXIT_MANY_ARGS "minishell: exit: too many arguments "

typedef struct s_data
{
    char    **argv;
    char    *flags;
    char    *cmd;
}   t_data;

// NOTE: a struct to contain enviromental variables where 'key'='value' (type export in bash to see)
typedef struct	s_env
{
	char		*key;
	char		*val;
	struct s_env	*next;
}   t_env;

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
	t_env	*env;
}		t_shell;
#endif
