/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:48:32 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/02 11:27:47 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	ch;

	ptr1 = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] == ch)
			return (ptr1 + i);
		i++;
	}
	return (NULL);
}
/*int	main()
{
    printf("%p\n", ft_memchr("hello", 'l', 5));
    return 0;
}*/
