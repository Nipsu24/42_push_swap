/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:44:01 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/26 16:01:03 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks at first options of rotate & rev_rotate, afterwards adjust cheapest nodes in case they have
//not been rotated to the top during these actions (or "if-conditions" did not apply to them)

void	push_a_to_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*cheapest;

	cheapest = get_cheapest(*lst_a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(lst_a, lst_b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		rev_rotate_both(lst_a, lst_b, cheapest);
	final_prep_push(lst_a, cheapest, 'a');
	final_prep_push(lst_b, cheapest->target_node, 'b');
	push_b(lst_a, lst_b);
}

t_list	*get_cheapest(t_list *lst)
{
	while (lst && !(lst->cheapest))
		lst = lst->next;
	return (lst);
}

void	rotate_both(t_list **lst_a, t_list **lst_b, t_list *cheapest)
{
	while (cheapest != *lst_a && cheapest->target_node != *lst_b)
		rotate_ab(lst_a, lst_b);
	set_index(*lst_a);
	set_index(*lst_b);
}

void	rev_rotate_both(t_list **lst_a, t_list **lst_b, t_list *cheapest)
{
	while (cheapest != *lst_a && cheapest->target_node != *lst_b)
		rev_rotate_ab(lst_a, lst_b);
	set_index(*lst_a);
	set_index(*lst_b);
}

void	final_prep_push(t_list **lst, t_list *cheapest, char stack)
{
	if (cheapest->above_median && stack == 'a')
	{
		while (*lst != cheapest)
			rotate_a(lst);
	}
	if (!(cheapest->above_median) && stack == 'a')
	{
		while (*lst != cheapest)
			rev_rotate_a(lst);
	}
	if (cheapest->above_median && stack == 'b')
	{
		while (*lst != cheapest)
			rotate_b(lst);
	}
	if (!(cheapest->above_median) && stack == 'b')
	{
		while (*lst != cheapest)
			rev_rotate_b(lst);
	}
}
