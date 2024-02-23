/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_to_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:35:54 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/23 16:13:17 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_to_sort(t_list **lst_a, t_list **lst_b)
{
	if (lst_len(*lst_a) == 2)
		sort_two(lst_a);
	if (lst_len(*lst_a) == 3)
		sort_three(lst_a);
	if (lst_len(*lst_a) > 3 && lst_len(*lst_a) < 6)
		sort_five(lst_a, lst_b);
	if (lst_len(*lst_a) > 5)
		sort_lst(lst_a, lst_b);
	return ;
}

void	sort_two(t_list **lst_a)
{
	t_list	*current;
	t_list	*last;

	current = *lst_a;
	last = current->next;
	if (current->content > last->content)
		swap_a(lst_a);
	return ;
}

void	sort_three(t_list **lst_a)
{
	t_list	*high;
	t_list	*low;
	t_list	*last;
	t_list	*first;

	high = highest(*lst_a);
	low = lowest(*lst_a);
	last = ft_lstlast(*lst_a);
	first = *lst_a;
	if (high == *lst_a && low == last)
	{
		rotate_a(lst_a);
		swap_a(lst_a);
	}
	if (low == *lst_a && low->next == high)
	{
		rev_rotate_a(lst_a);
		swap_a(lst_a);
	}
	if ((*lst_a)->next == high && low == last)
		rev_rotate_a(lst_a);
	if ((*lst_a) == high && (*lst_a)->next == low)
		rotate_a(lst_a);
	if ((*lst_a)->next == low && last == high)
		swap_a(lst_a);
}

void	sort_five(t_list **lst_a, t_list **lst_b)
{
	t_list	*low;
	t_list	*low_2;

	low = lowest((*lst_a));
	low_2 = NULL;
	while (*lst_a != low)
		rotate_a(lst_a);
	push_b(lst_a, lst_b);
	low_2 = lowest((*lst_a));
	while (*lst_a != low_2)
		rotate_a(lst_a);
	push_b(lst_a, lst_b);
	sort_three(lst_a);
	push_a(lst_a, lst_b);
	push_a(lst_a, lst_b);
}
