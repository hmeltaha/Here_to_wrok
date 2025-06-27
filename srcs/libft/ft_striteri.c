/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:14:43 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/05 15:51:36 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

/*void	ft_uppercase(unsigned int i, char *c)
{
	unsigned int	i;
	int				i;

	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -=32;
}*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*int main() 
{
	char s[] ="hala";
	ft_striteri(s, ft_uppercase);

	printf("%s" ,s);
	return (0);
}*/
