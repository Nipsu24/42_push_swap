/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:14:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/23 14:01:51 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **lst_a, t_list **lst_b)
{
	t_list	*current_b;
	t_list	*current_a;

	if (!lst_b || !*lst_b)
		return ;
	current_b = *lst_b;
	current_a = *lst_a;
	*lst_b = current_b->next;
	current_b->next = current_a;
	*lst_a = current_b;
	ft_putstr("pa\n");
}

void	push_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*current_b;
	t_list	*current_a;

	if (!lst_a || !*lst_a)
		return ;
	current_a = *lst_a;
	current_b = *lst_b;
	*lst_a = current_a->next;
	current_a->next = current_b;
	*lst_b = current_a;
	ft_putstr("pb\n");
}
