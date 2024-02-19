/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:34:33 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/19 12:12:49 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rotate_a(t_list **lst_a)
{
	t_list	*last;
	t_list	*current;

	if (!lst_a || !*lst_a || !(*lst_a)->next)
		return ;
	current = *lst_a;
	last = ft_lstlast(*lst_a);
	*lst_a = current->next;
	last->next = current;
	current->next = NULL;
	ft_putstr("ra\n");
}

void	rotate_b(t_list **lst_b)
{
	t_list	*last;
	t_list	*current;

	if (!lst_b || !*lst_b || !(*lst_b)->next)
		return ;
	current = *lst_b;
	last = ft_lstlast(*lst_b);
	*lst_b = current->next;
	last->next = current;
	current->next = NULL;
	ft_putstr("rb\n");
}

void	rotate_ab(t_list **lst_a, t_list **lst_b)
{
	t_list	*last_a;
	t_list	*current_a;
	t_list	*last_b;
	t_list	*current_b;

	current_a = *lst_a;
	last_a = ft_lstlast(*lst_a);
	*lst_a = current_a->next;
	last_a->next = current_a;
	current_a->next = NULL;
	current_b = *lst_b;
	last_b = ft_lstlast(*lst_b);
	*lst_b = current_b->next;
	last_b->next = current_b;
	current_b->next = NULL;
	ft_putstr("rr\n");
}
