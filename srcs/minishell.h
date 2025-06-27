#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <signal.h>
#include <limits.h>

#define PATH_MAX 4096

typedef struct s_shell
{
	int		argc;
	char	**argv;
	char	**envp;
	int		last_exit_status;
}	t_shell;

typedef struct s_command
{
    char **args; 
    //bool is_pipe;
    //t_redir **redirection;
    //int     redir_count; 
    struct s_command *next;
} t_command;

typedef struct s_quote_state
{
	int		in_single;
	int		in_double;
}			t_quote_state;

// parsing 


// execoting
char	**copying_env(char **old_env);

// utils


#endif