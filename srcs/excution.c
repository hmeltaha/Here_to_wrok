/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hala <hala@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:53:47 by hmeltaha          #+#    #+#             */
/*   Updated: 2025/06/27 20:12:48 by hala             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdbool.h>
#include "minishell.h"

// typedef struct s_shell
// {
// 	int		argc;
// 	char	**argv;
// 	char	**envp;
// 	int		last_exit_status;
// }	t_shell;

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	if (s1[i] == s2[i])
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}
bool is_builtin(char *cmd)
{
    int		i;
	char *builtins[] = {"cd", "echo", "pwd", "export", "unset", "env", "exit", NULL};
	
	i = 0;
    while (builtins[i])
    {
		if (!ft_strcmp(cmd, builtins[i]))
		return (true);
        i++;
    }
    return (false);
}

void 	builtin_env(t_shell *shell)
{

	int	i;
	
	i = 0;
	while(shell->envp[i])
	{
		if(ft_strchr(shell->envp[i], '='))
			printf("%s \n", shell->envp[i]);
		i++;
	}
}
//PATH_MAX = is a constant defiend in <limits.h> that represnt the max num of char in a full absulat file path 
// we need a buffer to store the current path
void  builtin_pwd(t_command *cmd)
{
		(void)cmd;	
		char path[PATH_MAX + 1];
		
		if(getcwd(path, sizeof(path)))
			printf("%s \n", path);
		return ;
}

void	builtin_echo(t_command *cmd)
{
	int	i;
	if(!cmd->args[1])
	{
		printf("\n");
		return ;
	}
	i = 1;
	while (cmd->args[i] && (ft_strcmp(cmd->args[i],"-n") == 0))
		i++;
	while (cmd->args[i])
	{
		printf("%s", cmd->args[i]);
		i++;
		if(cmd->args[i])
			printf(" ");
	}
	if (ft_strcmp(cmd->args[1],"-n"))
		printf("\n");
}
// void update_pwd_env(t_shell *shell, char *old_pwd)
// {
//     char *new_pwd;

//     new_pwd = getcwd(NULL, 0);
//     if (!new_pwd)
//         return ;
//     unset_env(shell, "OLDPWD");
//     export_env(shell, "OLDPWD", old_pwd);
//     unset_env(shell, "PWD");
//     export_env(shell, "PWD", new_pwd);
//     shell->last_exit_status = 0;
//     free(new_pwd);
// }

//void builtin_cd(t_command *cmd, t_shell *shell)
//{
//    char *old_pwd;
//    char *target;

//    old_pwd = getcwd(NULL, 0);
//    if (cmd->args[2])
//    {
//        printf("bash: cd: too many arguments\n");
//        shell->last_exit_status = 1;
//        free(old_pwd);
//        return ;
//    }
//    target = NULL;
//    if (!cmd->args[1])
//        target = get_env(shell, "HOME");
//    else
//        target = cmd->args[1];
//    if (chdir(target) == -1)
//    {
//        perror("bash: cd: No such file or directory");
//        shell->last_exit_status = 1;
//        free(old_pwd);
//        return ;
//    }
//    update_pwd_env(shell, old_pwd);
//    free(old_pwd);
//}
 int  args_count(char **str)
{
	int	i;
	i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}

int	is_numeric(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void builtin_exit(t_command *cmd, t_shell *shell)
{
	(void)shell;
	int	count;
	count = args_count(cmd->args);
	// printf("%d", count);
	if(count == 2)
	{
		if(is_numeric(cmd->args[0]))
		{
			printf("exit\n"); //exit with atoi(arg) % 256
		}
		else
		{
			// printf("exit\n");
			printf("exit\n bash: exit: numeric argument required");// exit with 255
		}
	}
	if(count > 2)
	{
		if(is_numeric(cmd->args[0]))
		{
			printf("exit\n");
			printf("exit: too many arguments");//do not exit
		}
		else
		{
			printf("exit\nexit: numeric argument required");
		}
	}
	else
	{
		//exit with last exit status
		printf("exit\n");
	}
}
int exec_builtin(t_command *cmd, t_shell *shell)
{
	if (!ft_strcmp(cmd->args[0], "pwd"))
			builtin_pwd(cmd);
	if (!ft_strcmp(cmd->args[0], "echo"))
			builtin_echo(cmd);
	if (!ft_strcmp(cmd->args[0], "env"))
			builtin_env(shell);
    // if (!ft_strcmp(cmd->args[0], "cd"))
    //     	builtin_cd(cmd, shell);
	if (!ft_strcmp(cmd->args[0], "exit"))
	    	builtin_exit(cmd, shell);
    //if (!ft_strcmp(cmd->args[0], "export"))
    //    	builtin_export(cmd, shell);
    //if (!ft_strcmp(cmd->args[0], "unset"))
    //    	builtin_unset(cmd, shell);
    return (1);
}


void execute_cmd(t_command *cmd, t_shell *shell)
{
	// if(cmd->is_pipe == true)
	// {
    	if (is_builtin(cmd->args[0]))
        	exec_builtin(cmd, shell);
    	else
		//exec_external(cmd, shell);
			return ;
	//}
	//else
	//{
	//	//  PIPE_HANDLING
	//	return
	//}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		shell;
	t_command	cmd;

	shell.argc = argc;
	shell.argv = argv;
	shell.envp = copying_env(envp);
	shell.last_exit_status = 42;

	cmd.args = calloc(3, sizeof(char *));
	if (!cmd.args)
		return (1);
	cmd.args[0] = ft_strdup("exit");
	cmd.args[1] = ft_strdup("");
	//cmd.args[1] = ft_strdup("-n-n");
	//cmd.args[2] = ft_strdup("hello");
	cmd.args[2] = NULL;


	execute_cmd(&cmd, &shell);

	//free(cmd.args[0]);
	free(cmd.args);
	
	// int i = 0;
	// while (shell.envp[i])
	// 	free(shell.envp[i++]);
	// free(shell.envp);

	return (0);
}

