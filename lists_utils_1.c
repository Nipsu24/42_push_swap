/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:17:56 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/08 12:19:10 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
