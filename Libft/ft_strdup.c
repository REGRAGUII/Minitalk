/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:30:19 by yregragu          #+#    #+#             */
/*   Updated: 2023/12/05 18:44:09 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	x;

	x = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (0);
	while (s1[x] != '\0')
	{
		dup[x] = s1[x];
		x++;
	}
	dup[x] = '\0';
	return (dup);
}
