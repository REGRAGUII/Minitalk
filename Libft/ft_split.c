/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:37:16 by yregragu          #+#    #+#             */
/*   Updated: 2023/12/09 22:17:34 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	tokenizer(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] != sep)
		{
			count++;
			while (str[i] != sep && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static	char	*wrd_malloc(const char *str, char sep)
{
	int		i;
	char	*word;

	i = 0;
	while (str && str[i] && str[i] != sep)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, i + 1);
	return (word);
}

static	char	**free_mem(char **buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		free(buff[i]);
		i++;
	}
	free(buff);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**buff;

	i = 0;
	j = 0;
	buff = (char **)malloc(sizeof(char *) * (tokenizer(s, c) + 1));
	if (!buff)
		return (NULL);
	while (s && s[i])
	{
		if (s[i] != c)
		{
			buff[j] = wrd_malloc(s + i, c);
			if (!buff[j])
				return (free_mem(buff));
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	buff[j] = NULL;
	return (buff);
}
