/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:58:53 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/07 16:58:53 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		be;
	int		en;
	char	*str;

	be = 0;
	en = 0;
	if (!s1 || !set)
	{
		return (NULL);
	}
	en = ft_strlen(s1);
	while (s1[be] && ft_strchr(set, s1[be]))
	{
		be++;
	}
	while (en > be && ft_strchr(set, s1[en - 1]))
	{
		en--;
	}
	str = (char *)malloc(sizeof(char) * (en - be + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + be, en - be);
	str[en - be] = '\0';
	return (str);
}
/*int main()
{
	char s1[] = "kHello, World!   ";
    char set1[] = "k ";
    char *result1 = ft_strtrim(s1, set1);
    printf("Trimmed result 1: '%s'\n", result1);
    free(result1);
return (0);
}*/
