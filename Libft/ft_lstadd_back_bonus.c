/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:41:09 by yregragu          #+#    #+#             */
/*   Updated: 2023/12/09 15:07:22 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!temp)
	{
		*lst = new;
		return ;
	}
	while (temp)
	{
		if (temp->next)
			temp = temp->next;
		else
		{
			temp->next = new;
			return ;
		}
	}
}
