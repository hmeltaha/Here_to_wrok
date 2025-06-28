#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define PATH_MAX 4096

typedef struct s_shell
{
	int					argc;
	char				**argv;
	char				**envp;
	int					last_exit_status;
}						t_shell;

typedef struct s_command
{
	char				**args;
	// bool is_pipe;
	// t_redir **redirection;
	// int     redir_count;
	struct s_command	*next;
}						t_command;

typedef struct s_quote_state
{
	int					in_single;
	int					in_double;
}						t_quote_state;

// parsing

char					**copying_env(char **old_env);
// execoting
// utils
int						is_numeric(char *str);
int						args_count(char **str);
int						ft_strcmp(char *s1, char *s2);
int						exec_builtin(t_command *cmd, t_shell *shell);
void					builtin_pwd(t_command *cmd);
void					builtin_echo(t_command *cmd);
void					builtin_env(t_shell *shell);
void					execute_cmd(t_command *cmd, t_shell *shell);
void					builtin_exit(t_command *cmd, t_shell *shell);
void					free_env_copy(char **env_copy);
void					clean_exit(t_shell *shell, long exit_code,t_command *cmd);
long	ft_atol(const char *nptr);
bool					is_builtin(char *cmd);
#endif