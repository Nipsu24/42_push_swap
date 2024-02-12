/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:13:05 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/12 15:02:35 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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

void	swap_a(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (!lst || !*lst || !(*lst)->next) // Check if list is empty or has only one node
		return ;
	current = *lst;
	temp = current->next; // points to 2nd node of list
	current->next = temp->next; // current next points now to 3rd node (the one initially temp->next has pointed)
	temp->next = current; //switches temp to 1st position
	*lst = temp; // Update the head of the list
	ft_putstr("sa\n");
}

void	swap_b(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (!lst || !*lst || !(*lst)->next) // Check if list is empty or has only one node
		return ;
	current = *lst;
	temp = current->next; // points to 2nd node of list
	current->next = temp->next; // current next points now to 3rd node (the one initially temp->next has pointed)
	temp->next = current; //switches temp to 1st position
	*lst = temp; // Update the head of the list
	ft_putstr("sb\n");
}

void	swap_ab(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp_a;
	t_list	*current_a;
	t_list	*temp_b;
	t_list	*current_b;

	if (!lst_a || !*lst_a || !(*lst_a)->next || !lst_b || !*lst_b || !(*lst_b)->next)
		return ;
	current_a = *lst_a;
	temp_a = current_a->next; // points to 2nd node of list
	current_a->next = temp_a->next; // current next points now to 3rd node (the one initially temp->next has pointed)
	temp_a->next = current_a; //switches temp to 1st position
	*lst_a = temp_a; // Update the head of the list
	current_b = *lst_b;
	temp_b = current_b->next; // points to 2nd node of list
	current_b->next = temp_b->next; // current next points now to 3rd node (the one initially temp->next has pointed)
	temp_b->next = current_b; //switches temp to 1st position
	*lst_b = temp_b; // Update the head of the list
	ft_putstr("ss\n");
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
    swap_ab(&root_a, &root_b);
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


/*
int	main(int ac, char *av[])
{
    int i;
    i = 1;
    
    t_list *root = NULL;
    if (ac < 2)
	{
		printf("%s\n", av[0]);
		return (0);
	}
    while (av[i])
	{
        t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = ft_atol(av[i]);
        stack_a->next = NULL;
		ft_lstadd_back(&root, stack_a);
		i++;
    }
    printf("%s\n", "before swap_a:");
    t_list *current = root;
    while (current != NULL)
    {
        printf("%ld\n", current->content);
        current = current->next;
    }
    printf("%s\n", "after swap_a:");
    swap_a(&root);
    t_list *current2 = root;
    while (current2 != NULL)
    {
        printf("%ld\n", current2->content);
        current2 = current2->next;
    }
    return (0);
}
*/
