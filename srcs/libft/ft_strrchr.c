/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:24:15 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/02 18:35:04 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	ch;

	i = ft_strlen(s);
	ptr = (char *)s;
	ch = (char)c;
	while (i >= 0)
	{
		if (ptr[i] == ch)
			return (ptr + i);
		i--;
	}
	return (NULL);
}
/*int	main()
{
printf("%s\n", ft_strrchr("hello world", 'o'));
    return (0);
}*/
