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
# include "msg.h"

typedef struct s_shell
{
	uint8_t	exit_code;
	char	**argv;
	char	*flags;
	char	*cmd;
}				t_shell;

typedef struct s_pipes
{
	char	**cmd; // only commands (like: ls, echo, pwd, grep, NULL)
	char	***cmd_args; // cmd + arg (like: [ls, -R, -a, NULL], [echo, -n, NULL], [pwd, NULL])
	char	*limiter; // when using heredoc: << EOF
	int		infd; // when redirecting input < infile
	int		outfd; // when redirecting output > outfile
	int		cmd_count; // number of commands (entries in **cmd without NULL)
	bool	here_doc; // do we use heredoc (input redirection "<<")
	bool	invalid_infile; // does the infile exist?
	bool	append; // do we use replace ">" or append ">>" with output redirection
}			t_pipes;

#endif
