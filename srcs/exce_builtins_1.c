/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exce_builtins_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <hmeltaha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:44 by hmeltaha          #+#    #+#             */
/*   Updated: 2025/06/28 11:44:20 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// PATH_MAX = is a constant defiend in <limits.h> that represnt the max num of char in a full absulat file path
// we need a buffer to store the current path
void	builtin_echo(t_command *cmd)
{
	int	i;

	if (!cmd->args[1])
	{
		printf("\n");
		return ;
	}
	i = 1;
	while (cmd->args[i] && (ft_strcmp(cmd->args[i], "-n") == 0))
		i++;
	while (cmd->args[i])
	{
		printf("%s", cmd->args[i]);
		i++;
		if (cmd->args[i])
			printf(" ");
	}
	if (ft_strcmp(cmd->args[1], "-n"))
		printf("\n");
}

void	builtin_pwd(t_command *cmd)
{
	char	path[PATH_MAX + 1];

	(void)cmd;
	if (getcwd(path, sizeof(path)))
		printf("%s \n", path);
	return ;
}

void	builtin_env(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->envp[i])
	{
		if (ft_strchr(shell->envp[i], '='))
			printf("%s \n", shell->envp[i]);
		i++;
	}
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

// void builtin_cd(t_command *cmd, t_shell *shell)
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
