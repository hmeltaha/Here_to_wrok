/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <hmeltaha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:55:02 by hmeltaha          #+#    #+#             */
/*   Updated: 2025/06/01 17:59:27 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_cmd_list(t_command *head)
{
	t_command *tmp;
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

t_command *create_new_node(void)
{
	t_command *node;
	node = malloc(sizeof(t_command));
	if(!node)
		return(NULL);
	ft_bzero(node, sizeof(t_command));
	return(node);
}
// main parsing function 
int count_pipes(char **token)
{
    int count ;
    int i ;
    count = 0;;
    i = -1;
    while(token[i])
    {
        if(strcmp(token[i], "|") == 0)
            count++;
        i++;
    }
    return(count + 1);
}