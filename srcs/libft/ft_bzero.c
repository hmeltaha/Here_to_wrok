/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:00:57 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/08/31 19:46:12 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*int main ()
{
	char buffer[10] = "ABCDEFGHIJ";
	bzero(buffer, 10);
	for (int i = 0; i < 10; i++) {
        printf("%c", buffer[i] ? buffer[i] : '.');
	}
    printf("\n");

    return (0);
}*/
