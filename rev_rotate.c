/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:06:12 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/26 10:27:10 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **lst_a)
{
	t_list	*last_a;
	t_list	*current_a;

	if (!lst_a || !*lst_a || !(*lst_a)->next)
		return ;
	last_a = ft_lstlast(*lst_a);
	current_a = *lst_a;
	while (current_a->next != last_a) //to identify 2nd last element of list
		current_a = current_a->next;
	last_a->next = *lst_a;
	*lst_a = last_a;
	current_a->next = NULL;
	ft_putstr("rra\n");
}

void	rev_rotate_b(t_list **lst_b)
{
	t_list	*last_b;
	t_list	*current_b;

	if (!lst_b || !*lst_b || !(*lst_b)->next)
		return ;
	last_b = ft_lstlast(*lst_b);
	current_b = *lst_b;
	while (current_b->next != last_b) //to identify 2nd last element of list
		current_b = current_b->next;
	last_b->next = *lst_b;
	*lst_b = last_b;
	current_b->next = NULL;
	ft_putstr("rrb\n");
}

void	rev_rotate_ab(t_list **lst_a, t_list **lst_b)
{
	t_list	*last_a;
	t_list	*current_a;
	t_list	*last_b;
	t_list	*current_b;

	if (!lst_a || !*lst_a || !(*lst_a)->next
		|| !lst_b || !*lst_b || !(*lst_b)->next)
		return ;
	last_a = ft_lstlast(*lst_a);
	current_a = *lst_a;
	while (current_a->next != last_a) //to identify 2nd last element of list
		current_a = current_a->next;
	last_a->next = *lst_a;
	*lst_a = last_a;
	current_a->next = NULL;
	last_b = ft_lstlast(*lst_b);
	current_b = *lst_b;
	while (current_b->next != last_b) //to identify 2nd last element of list
		current_b = current_b->next;
	last_b->next = *lst_b;
	*lst_b = last_b;
	current_b->next = NULL;
	ft_putstr("rrr\n");
}
