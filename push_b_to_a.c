/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:00:10 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/01 14:54:37 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_list_b(t_list *lst_a, t_list *lst_b)
{
	set_index(lst_a);
	set_index(lst_b);
	set_target_b(lst_a, lst_b);
}

void	set_target_b(t_list *lst_a, t_list *lst_b)
{
	t_list	*current_a;
	t_list	*target_node;
	int		closest_big;

	while (lst_b)
	{
		current_a = lst_a;
		closest_big = INT_MAX;
		while (current_a)
		{
			if (current_a->content > lst_b->content
				&& current_a->content < closest_big)
			{
				closest_big = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_big == INT_MAX)
			lst_b->target_node = lowest(lst_a);
		else
			lst_b->target_node = target_node;
		lst_b = lst_b->next;
	}
}
/*sorts list "a" once more: Rotates/rev_rotates a-node/target node of b
	until it's on top of list. Here in this context, "target node" 
	is "cheapest" of final_prep_push*/

void	push_b_to_a(t_list **lst_a, t_list **lst_b)
{
	final_prep_push(lst_a, (*lst_b)->target_node, 'a');
	push_a(lst_a, lst_b);
}

void	sort_a_final(t_list **lst_a)
{
	while (lowest(*lst_a)->content != (*lst_a)->content)
	{
		if (lowest(*lst_a)->above_median)
			rotate_a(lst_a);
		else
			rev_rotate_a(lst_a);
	}
}
