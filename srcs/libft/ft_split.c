/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:12:35 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/17 13:11:59 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c && in_word)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static int	allocate_and_copy_substrings(char **array, const char *s, char c)
{
	size_t	index;
	size_t	array_index;

	index = 0;
	array_index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		index = 0;
		while (s[index] && s[index] != c)
			index++;
		if (index > 0)
		{
			array[array_index] = ft_substr(s, 0, index);
			if (!array[array_index++])
				return (0);
		}
		s += index;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	substr_count;
	size_t	i;

	if (!s)
		return (NULL);
	substr_count = count_words(s, c);
	array = (char **)malloc((substr_count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!allocate_and_copy_substrings(array, s, c))
	{
		i = 0;
		while (i < substr_count)
			free(array[i++]);
		free(array);
		return (NULL);
	}
	array[substr_count] = NULL;
	return (array);
}
/*
int main(void)
{
    char **r = ft_split("hello farah" , ' ');
    size_t	i = 0;
    while (r[i])
    {
    printf("%s\n", r[i]);
    i++;
    }
    
    return (0);
}
*/
