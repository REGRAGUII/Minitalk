/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:32:08 by yregragu          #+#    #+#             */
/*   Updated: 2023/12/08 10:51:17 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	x;

	x = 0;
	srclen = ft_strlen((char *) src);
	if (size)
	{
		while (src[x] && x < size - 1)
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	return (srclen);
}
