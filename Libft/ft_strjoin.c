/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:54:23 by yregragu          #+#    #+#             */
/*   Updated: 2024/01/22 21:47:22 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	y;
	size_t	x;
	char	*s;

	x = 0;
	y = 0;
	if (!s1 || !s2)
		return (0);
	s = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (0);
	while (s1[x])
	{
		s[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		s[x] = s2[y];
		x++;
		y++;
	}
	s[x] = '\0';
	return (s);
}
