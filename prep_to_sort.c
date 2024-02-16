/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_to_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:35:54 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/16 14:22:16 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	prep_to_sort(t_list **lst_a, t_list **lst_b)
{
	if (lst_len(*lst_a) == 2)
		sort_two(lst_a);
	if (lst_len(*lst_a) == 3)
		sort_three(lst_a);
	if (lst_len(*lst_a) == 4)
		sort_four(lst_a, lst_b);
	return ;
}

void	sort_four(t_list **lst_a, t_list **lst_b)
{
	int		i;
	t_list	*current_a;
	t_list	*current_b;

	i = 0;
	current_a = *lst_a;
	current_b = *lst_b;
	push_b(lst_a, lst_b);
	sort_three(lst_a);
	current_a = *lst_a;
	current_b = *lst_b;
	while (current_a->content < current_b->content)
	{
		rotate_a(lst_a);
		i++;
		current_a = *lst_a;
	}
	push_a(lst_a, lst_b);
	while (i > 0)
	{
		rev_rotate_a(lst_a);
		i--;
	}
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

void	sort_three(t_list **lst_a)
{
	t_list	*high;
	t_list	*low;
	t_list	*last;
	t_list	*first;

	high = highest(*lst_a);
	low = lowest(*lst_a);
	last = ft_lstlast(*lst_a);
	first = *lst_a;
	if (high == *lst_a && low == last)
	{
		rotate_a(lst_a);
		swap_a(lst_a);
	}
	if (low == *lst_a && low->next == high)
	{
		rev_rotate_a(lst_a);
		swap_a(lst_a);
	}
	if ((*lst_a)->next == high && low == last)
		rev_rotate_a(lst_a);
	if ((*lst_a) == high && (*lst_a)->next == low)
		rotate_a(lst_a);
	if ((*lst_a)->next == low && last == high)
		swap_a(lst_a);
}



// void	sort_three(t_list **lst_a)
// {
// 	t_list	*cur;
// 	t_list	*end;
// 	t_list	*mid;

// 	cur = *lst_a;
// 	end = ft_lstlast(*lst_a);
// 	mid = cur->next;
// 	if (cur->content < mid->content && mid->content < end->content)
// 		return ;
// 	if (cur->content > mid->content && mid->content > end->content)
// 	{
// 		rotate_a(lst_a);
// 		swap_a(lst_a);
// 	}
// 	if (cur->content < mid->content && mid->content > end->content && cur->content < end->content)
// 	{
// 		rev_rotate_a(lst_a);
// 		swap_a(lst_a);
// 	}
// 	if (cur->content < mid->content && mid->content > end->content && cur->content > end->content)
// 		rev_rotate_a(lst_a);
// 	if (cur->content > mid->content && mid->content < end->content && cur->content > end->content)
// 		rotate_a(lst_a);
// 	if (cur->content > mid->content && mid->content < end->content && cur->content < end->content)
// 		swap_a(lst_a);
// }

int	main(int ac, char *av[])
{
	int	i;

	i = 1;
	t_list *root = NULL;
	t_list *root_b = NULL;
	while (ac > i)
	{
		t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = ft_atol(av[i]);
		stack_a->next = NULL;
		ft_lstadd_back(&root, stack_a);
		i++;
	}
    printf("%s\n", "before sorting:");
    t_list *current = root;
    while (current != NULL)
    {
        printf("%ld\n", current->content);
        current = current->next;
    }
    printf("%s\n", "after sorting:");
    prep_to_sort(&root, &root_b);
    t_list *current2 = root;
    while (current2 != NULL)
    {
        printf("%ld\n", current2->content);
        current2 = current2->next;
    }
    return (0);
}
