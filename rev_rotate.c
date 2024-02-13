/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:06:12 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/13 15:46:47 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rev_rotate_a(t_list **lst_a)
{
	t_list	*last_a;
	t_list	*current_a;

	if (!lst_a || !*lst_a || !(*lst_a)->next)
		return;
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
		return;
	last_b = ft_lstlast(*lst_b); 
	current_b = *lst_b; 
	while (current_b->next != last_b) //to identify 2nd last element of list
		current_b = current_b->next;
	last_b->next = *lst_b;
	*lst_b = last_b;
	current_b->next = NULL;
	ft_putstr("rrb\n");
}

int	main(void)
{
    int i;
    i = 1;
    t_list *root = NULL;
    while (i < 5)
	{
        t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = i;
        stack_a->next = NULL;
		ft_lstadd_back(&root, stack_a);
		i++;
    }
    printf("%s\n", "before rotate_a:");
    t_list *current = root;
    while (current != NULL)
    {
        printf("%ld\n", current->content);
        current = current->next;
    }
    printf("%s\n", "after rotate_a:");
    rev_rotate_b(&root);
    t_list *current2 = root;
    while (current2 != NULL)
    {
        printf("%ld\n", current2->content);
        current2 = current2->next;
    }
    return (0);
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