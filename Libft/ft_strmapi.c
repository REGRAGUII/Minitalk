/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:53:40 by yregragu          #+#    #+#             */
/*   Updated: 2023/12/08 10:50:23 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dup;
	int		l;

	if (!s || !f)
		return (0);
	l = ft_strlen(s);
	dup = malloc(sizeof(char) * (l + 1));
	if (!dup)
		return (0);
	l = 0;
	while (s[l])
	{
		dup[l] = f(l, s[l]);
		l++;
	}
	dup[l] = '\0';
	return (dup);
}
