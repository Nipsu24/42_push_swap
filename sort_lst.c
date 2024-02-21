/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:30:26 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/21 16:56:03 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//void	sort_lst(t_list **lst_a, t_list **lst_b)

/*sets index to each node of stack a and calculates whether
  it's below or above the median*/
// void	set_index(t_list *lst)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = lst_len(lst);
// 	if (!lst)
// 		return ;
// 	while (lst)
// 	{
// 		lst->index = i;
// 		if (lst->index <= len / 2)
// 			lst->above_median = true;
// 		else
// 			lst->above_median = false;
// 		lst = lst->next;
// 		i++;
// 	}
// }

void	set_target_node(t_list *lst_a, t_list *lst_b)
{
	t_list	*current_b;
	t_list	*target_node;
	long	closest_small;

	while (lst_a)
	{
		current_b = lst_b;
		closest_small = LONG_MIN;
		while (current_b)
		{
			if (current_b->content < lst_a->content
				&& current_b->content > closest_small)
			{
				closest_small = current_b->content;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_small == LONG_MIN)
			lst_a->target_node = highest(lst_b);
		else
			lst_a->target_node = target_node;
		printf("%ld", target_node->content);
		lst_a = lst_a->next;
	}
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
    printf("%s\n", "after set target node:");
    set_target_node(root_a, root_b);
    // t_list *current_a2 = root_a;
    // while (current_a2 != NULL)
    // {
    //     printf("%ld\n", current_a2->content);
    //     current_a2 = current_a2->next;
    // }
    // printf("%s\n", "after swap_ab b:");
    // //swap_ab(&root_a, &root_b);
    // t_list *current_b2 = root_b;
    // while (current_b2 != NULL)
    // {
    //     printf("%ld\n", current_b2->content);
    //     current_b2 = current_b2->next;
    // }
    return (0);
}
// int	main(void)
// {
//     int i;
//     i = 1;
//     t_list *root = NULL;
//     while (i < 8)
// 	{
//         t_list *stack_a = malloc(sizeof(t_list));
// 		if (!stack_a)
// 			return (0);
// 		stack_a->content = i;
//         stack_a->next = NULL;
// 		ft_lstadd_back(&root, stack_a);
// 		i++;
//     }
// 	set_index(root);
//     // printf("%s\n", "before rotate_a:");
//     // t_list *current = root;
//     // while (current != NULL)
//     // {
//     //     printf("%ld\n", current->content);
//     //     current = current->next;
//     // }
//     // printf("%s\n", "after rotate_a:");
//     // rev_rotate_b(&root);
//     // t_list *current2 = root;
//     // while (current2 != NULL)
//     // {
//     //     printf("%ld\n", current2->content);
//     //     current2 = current2->next;
//     // }
//     return (0);
// }