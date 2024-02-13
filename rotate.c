/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:34:33 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/13 14:54:53 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

//for testing double commands

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
    rotate_ab(&root_a, &root_b);
    t_list *current_a2 = root_a;
    while (current_a2 != NULL)
    {
        printf("%ld\n", current_a2->content);
        current_a2 = current_a2->next;
    }
    printf("%s\n", "after swap_ab b:");
    t_list *current_b2 = root_b;
    while (current_b2 != NULL)
    {
        printf("%ld\n", current_b2->content);
        current_b2 = current_b2->next;
    }
    return (0);
}


//for testing single commands

/*
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
    rotate_a(&root);
    t_list *current2 = root;
    while (current2 != NULL)
    {
        printf("%ld\n", current2->content);
        current2 = current2->next;
    }
    return (0);
}
*/

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