/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:27:49 by yregragu          #+#    #+#             */
/*   Updated: 2023/12/04 22:23:17 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*re;
	int		i;

	re = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			re = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		re = (char *)&s[i];
	return (re);
}
