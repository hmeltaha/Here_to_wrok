/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:27:52 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/02 20:30:30 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = ft_strlen(s) + 1;
	ptr = (char *)malloc(i * sizeof(char));
	if (!(ptr))
		return (NULL);
	ptr[i] = '\0';
	while (--i >= 0)
		ptr[i] = s[i];
	return (ptr);
}
/*int	main()
{
    char *copy;
    copy = ft_strdup("Hello!");
    printf("Copy: %s\n", copy);
    free(copy);
    return 0;
}*/
