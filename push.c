/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:14:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/12 16:26:28 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	push_a(t_list **lst_a, t_list **lst_b)
{
	t_list	*current_b;
	t_list	*current_a;

	if (!lst_b || !*lst_b)
		return ;
	current_b = *lst_b;
	current_a = *lst_a;
	current_a->prev = current_b;
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
	current_b->prev = current_a;
	*lst_a = current_a->next;
	current_a->next = current_b;
	*lst_b = current_a;
	ft_putstr("pb\n");
}

int	main(void)
{
    int i;
    int j;
    i = 0;
    j = 5;
    
    t_list *root_a = NULL;
    t_list *root_b = NULL;
    
    while (i < 5)
	{
        t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = i;
        stack_a->next = NULL;
		ft_lstadd_back(&root_a, stack_a);
		i++;
    }
    while (j < 10)
	{
        t_list *stack_b = malloc(sizeof(t_list));
		if (!stack_b)
			return (0);
		stack_b->content = j;
        stack_b->next = NULL;
		ft_lstadd_back(&root_b, stack_b);
		j++;
    }
    printf("%s\n", "before swap_ab a:");
    t_list *current_a = root_a;
    while (current_a != NULL)
    {
        printf("%ld\n", current_a->content);
        current_a = current_a->next;
    }
    printf("%s\n", "before swap_ab b:");
    t_list *current_b = root_b;
    while (current_b != NULL)
    {
        printf("%ld\n", current_b->content);
        current_b = current_b->next;
    }
    printf("%s\n", "after swap_ab a:");
    push_b(&root_a, &root_b);
    t_list *current_a2 = root_a;
    while (current_a2 != NULL)
    {
        printf("%ld\n", current_a2->content);
        current_a2 = current_a2->next;
    }
    printf("%s\n", "after swap_ab b:");
    /*swap_ab(&root_a, &root_b);*/
    t_list *current_b2 = root_b;
    while (current_b2 != NULL)
    {
        printf("%ld\n", current_b2->content);
        current_b2 = current_b2->next;
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