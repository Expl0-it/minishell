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

typedef enum e_err_exit
{
	OK,
	MALLOC_ERR,
	PIPE_ERR,
	FORK_ERR,
}			t_err_exit;

typedef enum e_write_mode
{
	REPLACE,
	APPEND,
}			t_write_mode;

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
	char			**cmd; // cmd + arg (like: [ls, -R -la, NULL] or [echo, -n, NULL] or [pwd, NULL])
	char			*limiter; // when using heredoc: << limiter || else NULL
	char			*infile; // NOTE: those should be also helpful to you to handle opening the files and put fds to struct
	char			*outfile; // NOTE: those should be also helpful to you to handle opening the files and put fds to struct
	int				fds[2];
	int				infd; // when redirecting input < infile
	int				outfd; // when redirecting output > outfile
	int 			old_outfd;
	pid_t			pid; // current proccess pid
	bool			heredoc; // do we use heredoc (input redirection "<<")
	bool			invalid_infile; // does the infile exist and do we have premissions to it?
	t_write_mode	write_mode; // do we use replace ">" or append ">>" file's contents with output redirection
}			t_pipes;

typedef struct s_data
{
	uint8_t	exit_code;
	uint8_t	cmd_exit_code;
	t_env	*env;
	t_pipes	*pipes;
	char	**args;
	char	*flags;
	char	*cmd;
	char	**envp;
}   t_data;

// utils
// free_arr.c
void	free_str_arr(char **arr, int to_be_freed);
void	free_2d_str_arr(char ***arr, int to_be_freed);
// err_exit.c
void	err_exit(t_data *data, char *msg, t_err_exit status);
void	exit_error(char *message);
// path_utils.c
char	*join_paths(char *p1, char *p2);
char	*find_valid_bin_path(char *bin_name, char **split);

// builtins
int		ft_env(t_data *data);
int		ft_pwd(void);
int		ft_echo(char **args);
int		ft_exit(t_data *data, char **args);
int		ft_unset(t_data *data, char **args);
int		ft_export(t_data *data, char **args);
int		ft_cd(t_data *data, char **args);

// env
int	init_env(t_data *data, char **envp); //changed to t_data *data
// modify_env.c
bool	overwrite_env_var(t_env *overwrite, char **split);
bool	set_env_var(t_env *env, char *key, char *val);
bool	rm_env_var(t_env *env, char *key);
// create_env.c
t_env	*new_env_node(char **split);
bool	create_env_var(t_env *env, char *env_literal);
// utils_env.c
char	*concat_split(char **split, char split_delimeter, int i_start);
bool	is_valid_env_var(char **split);
void	free_env_var(t_env *env_var);
void	free_env(t_env *env);
// get_env.c
t_env	*get_env_node(t_env *env, char *key);
t_env	*get_env_last_node(t_env *env);
int		get_env_size(t_env *env);
char	*get_env_val(t_env *env, char *key);

// signals
void	sig_int(int sig);
void	sig_term(int sig);
void	init_signals(void);

// parser
void	parse_input(t_data *data, char *line);
void    parse_env(t_data *data);
void	skip_spaces(char **line);
bool	is_space(char c);
bool	is_quote(char c);

// lexer
void	lexer(t_data *data);

void set_append(char **args, int j, t_pipes *pipe);
void set_heredoc(t_pipes *pipe, char *arg);
void set_redirection(char **args, int j, t_pipes *pipe);
// exec
// exec.c
void	execute(t_data *data);
// pipes.c
void	open_pipes(t_data *data);
void	close_pipes(t_data *data);
void	close_useless_pipes(t_data *data, int i_pipe);
// redirections.c
void	handle_redirections(t_data *data, int i);
// paths.c
char	*get_path(t_data *data, int i);

// clenup_req.c
void	cleanup_req(t_data *data);

#endif
