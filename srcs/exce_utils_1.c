/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exce_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <hmeltaha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:36:46 by hmeltaha          #+#    #+#             */
/*   Updated: 2025/06/28 15:30:27 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

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

static int	is_within_long_limit(char *str, int start, int is_negative)
{
	char	*limit;
	int		i;

	if (is_negative)
		limit = "9223372036854775808";
	else
		limit = "9223372036854775807";
	i = 0;
	while (i < 19)
	{
		if (str[start + i] > limit[i])
			return (0);
		if (str[start + i] < limit[i])
			return (1);
		i++;
	}
	return (1);
}

int	is_numeric(char *str)
{
	int	i;
	int	digit_count;
	int	is_negative;

	if (!str || !str[0])
		return (0);
	i = 0;
	is_negative = 0;
	if (str[i] == '+' || str[i] == '-')
	{
    	if (str[i] == '-')
        	is_negative = 1;
    	i++;	
	}
	if (!str[i])
		return (0);
	digit_count = 0;
	while (str[i + digit_count])
	{
		if (!ft_isdigit(str[i + digit_count]))
			return (0);
		digit_count++;
	}
	if (digit_count > 19)
		return (0);
	if (digit_count == 19 && !is_within_long_limit(str, i, is_negative))
		return (0);
	return (1);
}






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