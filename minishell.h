/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:43:42 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/12 17:09:49 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef PATH_LEN
#  define PATH_MAX 4096
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
# include "get_next_line/get_next_line.h"

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

// NOTE: contain enviromental variables where 'key'='value'
typedef struct s_env
{
	char			*key;
	char			*val;
	struct s_env	*next;
}				t_env;

typedef struct s_pipes
{
	char			**cmd;
	char			*limiter;
	char			*infile;
	char			*outfile;
	int				fds[2];
	int				infd;
	int				outfd;
	int				old_outfd;
	pid_t			pid;
	bool			heredoc;
	bool			invalid_infile;
	t_write_mode	write_mode;
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
}			t_data;

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
int		ft_exit(t_data *data, char **args, int i);
int		ft_unset(t_data *data, char **args);
int		ft_export(t_data *data, char **args);
int		ft_cd(t_data *data, char **args);

// env
int		init_env(t_data *data, char **envp); //changed to t_data *data
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
void	parse_env(t_data *data);
void	skip_spaces(char **line);
bool	is_space(char c);
bool	is_quote(char c);

// lexer
void	lexer(t_data *data);

void	set_append(char **args, int j, t_pipes *pipe);
void	set_heredoc(t_pipes *pipe, char *arg);
void	set_redirection(char **args, int j, t_pipes *pipe);
void	set_operators(char **args, int *i, t_pipes *pipe);
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

// cleanup_iter.c
void	cleanup_iter(t_data *data);
// cleanup_exit.c
void	cleanup_exit(t_data *data);

#endif
