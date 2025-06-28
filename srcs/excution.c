/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <hmeltaha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:53:47 by hmeltaha          #+#    #+#             */
/*   Updated: 2025/06/28 15:40:15 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

#include "minishell.h"

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
	cmd.args[1] = ft_strdup("9223372036854775808");
	//cmd.args[2] = ft_strdup("-33");
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

