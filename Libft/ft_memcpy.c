/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 01:05:49 by yregragu          #+#    #+#             */
/*   Updated: 2023/12/07 22:28:31 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	x;

	if (!dest && !src)
		return (0);
	x = 0;
	while (x < n)
	{
		*((unsigned char *)(dest + x)) = *((unsigned char *)(src + x));
		x++;
	}
	return (dest);
}
