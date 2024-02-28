/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:36:05 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/26 16:03:54 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_list_a(t_list *lst_a, t_list *lst_b)
{
	set_index(lst_a);
	set_index(lst_b);
	set_target_node(lst_a, lst_b);
	calc_push_cost(lst_a, lst_b);
	find_cheapest(lst_a);
}
/*sets index to each node of stack a and calculates whether
  it's below or above the median*/

void	set_index(t_list *lst)
{
	int	i;
	int	len;

	i = 0;
	len = lst_len(lst);
	if (!lst)
		return ;
	while (lst)
	{
		lst->index = i;
		if (lst->index <= len / 2)
			lst->above_median = true;
		else
			lst->above_median = false;
		lst = lst->next;
		i++;
	}
}
/*searches for smallest closest node in lst b for nodes of lst a
  in case no smaller node is found, target node for node a is set to 
  highest node of b*/

void	set_target_node(t_list *lst_a, t_list *lst_b)
{
	t_list	*current_b;
	t_list	*target_node;
	long	closest_small;

	while (lst_a)
	{
		current_b = lst_b;
		closest_small = LONG_MIN; // INT_MIN sufficient?
		while (current_b)
		{
			if (current_b->content < lst_a->content
				&& current_b->content > closest_small)
			{
				closest_small = current_b->content;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_small == LONG_MIN) // INT_MIN sufficient?
			lst_a->target_node = highest(lst_b);
		else
			lst_a->target_node = target_node;
		lst_a = lst_a->next;
	}
}
/* calculates push costs for lst a and b, checks for each node in each stack
	whether it's above or below median and sets costs accordingly to index of node*/

void	calc_push_cost(t_list *lst_a, t_list *lst_b)
{
	int	len_a;
	int	len_b;

	len_a = lst_len(lst_a);
	len_b = lst_len(lst_b);
	while (lst_a)
	{
		if (lst_a->target_node)
		{
			lst_a->push_cost = lst_a->index;
			if (!(lst_a->above_median))
				lst_a->push_cost = len_a - (lst_a->index);
			if (lst_a->target_node->above_median)
				lst_a->push_cost += lst_a->target_node->index;
			else
				lst_a->push_cost += len_b - (lst_a->target_node->index);
		}
		lst_a = lst_a->next;
	}
}
/*checks sum of push costs of node + target node, node with
   smallest value is given out by temp and it's bool "cheapest" is set to true*/

void	find_cheapest(t_list *lst_a)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!lst_a)
		return ;
	cheapest_value = LONG_MAX;
	while (lst_a)
	{
		if (lst_a->push_cost < cheapest_value)
		{
			cheapest_value = lst_a->push_cost;
			cheapest_node = lst_a;
		}
		lst_a = lst_a->next;
	}
	cheapest_node->cheapest = true;
}
