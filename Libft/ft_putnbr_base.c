/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:01:22 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/28 20:06:22 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned long n, char c, int *len)
{
	unsigned int	base_len;
	char			*base;

	base_len = 16;
	if (c != 'p')
		n = (unsigned int)n;
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < base_len)
		ft_putchar(base[n % base_len], len);
	else
	{
		ft_putnbr_base(n / base_len, c, len);
		ft_putnbr_base(n % base_len, c, len);
	}
}
