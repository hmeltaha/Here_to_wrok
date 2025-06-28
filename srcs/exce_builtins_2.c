/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exce_builtins_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <hmeltaha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:47:24 by hmeltaha          #+#    #+#             */
/*   Updated: 2025/06/28 15:42:44 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long	ft_atol(const char *nptr)
{
	long	result;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] == ' ') || ((nptr[i] >= 9) && (nptr[i] <= 13)))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
void	clean_exit(t_shell *shell, long exit_code, t_command *cmd)
{
	(void)cmd;

	if (!shell)
		exit(exit_code);
	// Free command list
	// free_commands(cmd);
	if (shell->envp)
		free_env_copy(shell->envp);
	// Free input line buffer (if you're storing it)
	// if (shell->line)
	//     free(shell->line);
	// Close and free pipe fds (if implemented)
	// close_all_pipes(shell);
	// Clear readline history (important if using readline)
	//clear_history();
	exit(exit_code);
}

static void	print_numric_error(char *arg)
{
	write(2, "bash: exit: ", 12);
	write(2, arg, ft_strlen(arg));
	write(2, ": numeric argument required\n", 28);
}

void	builtin_exit(t_command *cmd, t_shell *shell)
{
	int	count;

	count = args_count(cmd->args);
	printf("exit\n");
	if (count == 2)
	{
		if (!(is_numeric(cmd->args[1])))
		{
			print_numric_error(cmd->args[1]);
			clean_exit(shell, 2, cmd);
		}
		clean_exit(shell, ft_atol((const char *)cmd->args[1]), cmd);
	}
	if (count > 2 && is_numeric(cmd->args[1]))
	{
		write(2, "bash: exit: too many arguments\n", 31);
		shell->last_exit_status = 1;
	}
	if (count > 2 && !is_numeric(cmd->args[1]))
	{
		print_numric_error(cmd->args[1]);
		clean_exit(shell, 2, cmd);
	}
	clean_exit(shell, shell->last_exit_status, cmd);
}
