/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:43:10 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/02 18:44:49 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	i = 0;
	ptr1 = (char *)haystack;
	ptr2 = (char *)needle;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (ptr1[i] && ft_strlen(ptr2) + i <= len)
	{
		if (ft_strncmp(ptr1 + i, ptr2, ft_strlen(ptr2)) == 0)
			return (ptr1 + i);
		i++;
	}
	return (NULL);
}
/*int	main()
{
char *result = ft_strnstr("hi my name is hala", "hala", 18);
printf("%s\n", result);
return(0);
}*/
