/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_to_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:35:54 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/14 16:57:13 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	prep_to_sort(t_list **lst_a, t_list **lst_b)
{
	if (lst_len(*lst_a) == 2)
		sort_two(lst_a);
	return ;
}

void	sort_two(t_list **lst_a)
{
	t_list	*current;
	t_list	*last;

	current = *lst_a;
	last = current->next;
	if (current->content > last->content)
		swap_a(lst_a);
	return ;
}

int	lst_len(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);		
}

int	main(void)
{
    int i;
    int j;
    i = 2;
    j = 5;

    t_list *root_a = NULL;
    t_list *root_b = NULL;

    while (i > 0)
	{
        t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = i;
        stack_a->next = NULL;
		ft_lstadd_back(&root_a, stack_a);
		i--;
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
    prep_to_sort(&root_a, &root_b);
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
