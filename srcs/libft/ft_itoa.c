/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:14:34 by hmeltaha          #+#    #+#             */
/*   Updated: 2024/09/06 11:17:36 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_len(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*s;
	long			nb;
	unsigned int	i;

	nb = n;
	i = ft_count_len(nb);
	s = malloc((i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[i--] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		s[0] = '-';
	}
	else if (nb == 0)
		s[0] = '0';
	while (nb > 0)
	{
		s[i--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (s);
}
/*
int	main(void)
{
	int	n;

	n = -2147483648;
	printf("%d\n", ft_count_len(n));
	printf("%s", (ft_itoa(n)));
	return (0);
}
*/
