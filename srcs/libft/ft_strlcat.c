/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:46:22 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/02 15:12:27 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		res;
	size_t		len_des;
	size_t		len_src;

	i = 0;
	res = 0;
	len_des = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize < len_des)
		return (len_src + dstsize);
	else
		res = (len_des + len_src);
	while (src[i] && len_des + 1 < dstsize)
	{
		dst[len_des] = src[i];
		len_des++;
		i++;
	}
	dst[len_des] = '\0';
	return (res);
}
/*int	main()
{
 char dest[20] = "hala";
  char src[] = "taha";
 printf("%zu",  ft_strlcat(dest, src, sizeof(dest)));
return(0);
}*/
