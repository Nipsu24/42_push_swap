/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:13:05 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/01 15:42:55 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	current = *lst;
	temp = current->next;
	current->next = temp->next;
	temp->next = current;
	*lst = temp;
	ft_putstr("sa\n");
}

void	swap_b(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	current = *lst;
	temp = current->next;
	current->next = temp->next;
	temp->next = current;
	*lst = temp;
	ft_putstr("sb\n");
}

void	swap_ab(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp_a;
	t_list	*current_a;
	t_list	*temp_b;
	t_list	*current_b;

	if (!lst_a || !*lst_a || !(*lst_a)->next
		|| !lst_b || !*lst_b || !(*lst_b)->next)
		return ;
	current_a = *lst_a;
	temp_a = current_a->next;
	current_a->next = temp_a->next;
	temp_a->next = current_a;
	*lst_a = temp_a;
	current_b = *lst_b;
	temp_b = current_b->next;
	current_b->next = temp_b->next;
	temp_b->next = current_b;
	*lst_b = temp_b;
	ft_putstr("ss\n");
}
