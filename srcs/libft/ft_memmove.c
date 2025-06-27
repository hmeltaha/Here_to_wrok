/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:42:27 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/01 16:33:45 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			len;

	len = n;
	if (!dest && !src)
		return (0);
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	if (src >= dest)
		ft_memcpy(dest, src, len);
	else
		while (len--)
			ptr1[len] = ptr2[len];
	return ((void *)ptr1);
}
/*int main() 
{
char overlap[] = "123456789";
    ft_memmove(overlap + 3, overlap, 6);
    printf("Overlap after memmove: %s\n", overlap);
return (0);
}*/
