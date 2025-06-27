/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:44:36 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/03 17:54:48 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*ptr;
	size_t	copy_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (str_len - start < len)
		copy_len = str_len - start;
	else
		copy_len = len;
	ptr = (char *)malloc((copy_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < copy_len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*int	main()
{
char *str = "hello world";
char *substr = ft_substr(str, 7, 5);
printf("%s", substr);
return(0);
}*/
