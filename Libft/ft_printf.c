/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:32:45 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/28 20:06:42 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_flag_checker(va_list args, char c, int *len)
{
	if (c == '%')
		ft_putchar('%', len);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (c == 'u')
		ft_putnbr(va_arg(args, unsigned int), len);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(args, long), c, len);
	else if (c == 'p')
	{
		ft_putstr("0x", len);
		ft_putnbr_base(va_arg(args, long), c, len);
	}
	else
		ft_putchar(c, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_flag_checker(args, *format, &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
