/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:40:46 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/11 17:38:06 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	ch;

	i = 0;
	ptr = (char *)s;
	ch = (char)c;
	if (!ch)
		return (ptr + ft_strlen(ptr));
	if (c == 0)
		return (ptr + ft_strlen(ptr));
	while (ptr[i])
	{
		if (ptr[i] == ch)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
/*int	main(void)
{
    char *result = ft_strchr("hello", 'l');
    printf("Result: %s\n");
    return (0);
}*/
