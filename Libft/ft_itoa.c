/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:19:36 by yregragu          #+#    #+#             */
/*   Updated: 2023/12/08 13:22:34 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static	char	*ft_isnegative(long n, int length)
{
	char	*str;

	if (n == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	n *= -1;
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	str[0] = '-';
	str[length] = '\0';
	length--;
	while (n)
	{
		str[length] = n % 10 + 48;
		n = n / 10;
		length--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*str;

	length = ft_count(n);
	if (n <= 0)
		return (ft_isnegative((long)n, length));
	str = malloc((sizeof(char) * length) + 1);
	if (!str)
		return (NULL);
	str[length] = '\0';
	length--;
	while (n)
	{
		str[length] = n % 10 + 48;
		n = n / 10;
		length--;
	}
	return (str);
}
