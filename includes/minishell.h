#ifndef MINISHELL_H
# define MINISHELL_H

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
# include "../libft/libft.h"

typedef struct s_hell
{
	char	**argv;
	char	*flags;
	char	*cmd;
}				t_hell;

typedef struct s_pipes
{
	int		infd;
	int		outfd;
	int		cmd_count;
	bool	here_doc;
	bool	invalid_infile;
	char	**cmd;
	char	***cmd_args;
}			t_pipes;

#endif
