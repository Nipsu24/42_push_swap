/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:30:26 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/23 16:20:45 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_lst(t_list **lst_a, t_list **lst_b)
{
	int	len;

	len = lst_len(*lst_a);
	while (len > 3)
	{
		prep_list_a(*lst_a, *lst_b);
		push_a_to_b(lst_a, lst_b);
		len--;
	}
	//for printing
	t_list *current = *lst_a;
    while (current != NULL)
    {
        printf("%ld\n", current->content);
        current = current->next;
    }
	t_list *current2 = *lst_b;
    while (current2 != NULL)
    {
        printf("%ld\n", current2->content);
        current2 = current2->next;
    }
	// sort_three(lst_a);
	// while (*lst_b)
	// {
	// 	prep_list_b(*lst_a, *lst_b);
	// 	push_b_to_a(lst_a, lst_b);
	// }
	// set_index(*lst_a);
	// sort_a_final(lst_a);
}


// int	main(void)
// {
//     int i;
//     int j;
//     i = 0;
//     j = 5;

//     t_list *root_a = NULL;
//     t_list *root_b = NULL;

//     while (i < 5)
// 	{
//         t_list *stack_a = malloc(sizeof(t_list));
// 		if (!stack_a)
// 			return (0);
// 		stack_a->content = i;
//         stack_a->next = NULL;
// 		ft_lstadd_back(&root_a, stack_a);
// 		i++;
//     }
//     while (j < 10)
// 	{
//         t_list *stack_b = malloc(sizeof(t_list));
// 		if (!stack_b)
// 			return (0);
// 		stack_b->content = j;
//         stack_b->next = NULL;
// 		ft_lstadd_back(&root_b, stack_b);
// 		j++;
//     }
//     printf("%s\n", "before swap_ab a:");
//     t_list *current_a = root_a;
//     while (current_a != NULL)
//     {
//         printf("%ld\n", current_a->content);
//         current_a = current_a->next;
//     }
//     printf("%s\n", "before swap_ab b:");
//     t_list *current_b = root_b;
//     while (current_b != NULL)
//     {
//         printf("%ld\n", current_b->content);
//         current_b = current_b->next;
//     }
//     printf("%s\n", "after set target node:");
//     set_index(root_a);
// 	set_index(root_b);
// 	set_target_node(root_a, root_b);
// 	calc_push_cost(root_a, root_b);
// 	find_cheapest(root_a);
//     // t_list *current_a2 = root_a;
//     // while (current_a2 != NULL)
//     // {
//     //     printf("%ld\n", current_a2->content);
//     //     current_a2 = current_a2->next;
//     // }
//     // printf("%s\n", "after swap_ab b:");
//     // //swap_ab(&root_a, &root_b);
//     // t_list *current_b2 = root_b;
//     // while (current_b2 != NULL)
//     // {
//     //     printf("%ld\n", current_b2->content);
//     //     current_b2 = current_b2->next;
//     // }
//     return (0);
// }
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