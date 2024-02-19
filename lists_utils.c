/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:17:56 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/19 12:02:23 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*highest(t_list *lst)
{
	t_list	*cur;
	t_list	*highest;

	cur = lst;
	highest = cur;
	if (!lst)
		return (NULL);
	while (cur)
	{
		if (cur->content > highest->content)
			highest = cur;
		cur = cur->next;
	}
	return (highest);
}

t_list	*lowest(t_list *lst)
{
	t_list	*cur;
	t_list	*lowest;

	cur = lst;
	lowest = cur;
	if (!lst)
		return (NULL);
	while (cur)
	{
		if (cur->content < lowest->content)
			lowest = cur;
		cur = cur->next;
	}
	return (lowest);
}

int	is_sorted(t_list *lst)
{
	t_list	*after;

	after = lst->next;
	while (lst && after)
	{
		if (lst->content > after->content)
			return (0);
		lst = lst->next;
		after = after->next;
	}
	return (1);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next)
		temp = temp -> next;
	temp -> next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst -> next)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

int	lst_len(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
