/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:29:49 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/08/31 16:37:17 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	ch;

	i = 0;
	ptr = b;
	ch = (unsigned char)c;
	while (i < len)
	{
		ptr[i] = ch;
		i++;
	}
	return (ptr);
}
/*int main()
{
char s[50];
ft_memset(s,'a', 12);
for (int i = 0; i<10 ;++i){
printf("%c" , s[i]);
}
return(0);
}*/
