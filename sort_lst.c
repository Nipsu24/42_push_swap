/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:30:26 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/22 16:21:09 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//void	sort_lst(t_list **lst_a, t_list **lst_b)

// void	prep_list(t_list *lst_a, t_list *lst_b)
// {
// 	set_index(lst_a);
// 	set_index(lst_b);
// 	set_target_node(lst_a, lst_b);
// 	calc_push_cost(lst_a, lst_b);
// 	find_cheapest(lst_a);
// }

//rotate and other commands to be changed to single functions -> 4 functions in total

void	push_a_to_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*cheapest;
	t_list	*top_a;
	t_list	*top_b;

	top_a = *lst_a;
	top_b = *lst_b;
	cheapest = find_cheapest(lst_a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_ab(&lst_a, &lst_b);
	if (!(cheapest->above_median) && cheapest->target_node->above_median)
	{
		rev_rotate_a(&lst_a);
		rotate_b(&lst_b);
	}
	if (cheapest->above_median && !(cheapest->target_node->above_median))
	{
		rotate_a(&lst_a);
		rev_rotate_b(&lst_b);
	}
	if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		rev_rotate_ab(&lst_a, &lst_b);
}

/*sets index to each node of stack a and calculates whether
  it's below or above the median*/
void	set_index(t_list *lst)
{
	int	i;
	int	len;

	i = 0;
	len = lst_len(lst);
	if (!lst)
		return ;
	while (lst)
	{
		lst->index = i;
		if (lst->index <= len / 2)
			lst->above_median = true;
		else
			lst->above_median = false;
		lst = lst->next;
		i++;
	}
}

/*searches for smallest closest node in lst b for nodes of lst a
  in case no smaller node is found, target node for node a is set to 
  highest node of b*/
void	set_target_node(t_list *lst_a, t_list *lst_b)
{
	t_list	*current_b;
	t_list	*target_node;
	long	closest_small;

	while (lst_a)
	{
		current_b = lst_b;
		closest_small = LONG_MIN; // INT_MIN sufficient?
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
		if (closest_small == LONG_MIN) // INT_MIN sufficient?
			lst_a->target_node = highest(lst_b);
		else
			lst_a->target_node = target_node;
		//printf("%ld", lst_a->target_node->content);
		lst_a = lst_a->next;
	}
}
/* calculates push costs for lst a and b, checks for each node in each stack
	whether it's above or below median and sets costs accordingly to index of node*/
void	calc_push_cost(t_list *lst_a, t_list *lst_b)
{
	int	len_a;
	int	len_b;

	len_a = lst_len(lst_a);
	len_b = lst_len(lst_b);
	while (lst_a)
	{
		if (lst_a->above_median == true)
			lst_a->push_cost = lst_a->index;
		if (lst_a->above_median == false)
			lst_a->push_cost = len_a - lst_a->index;
		//printf("push cost: %d\n", lst_a->push_cost);
		lst_a = lst_a->next;
	}
	while (lst_b)
	{
		if (lst_b->above_median == true)
			lst_b->push_cost = lst_b->index;
		if (lst_b->above_median == false)
			lst_b->push_cost = len_b - lst_b->index;
		//printf("push cost: %d\n", lst_b->push_cost);
		lst_b = lst_b->next;
	}
}
/*checks sum of push costs of node + target node, node with
   smallest value is given out by temp and it's bool "cheapest" is set to true*/

void	find_cheapest(t_list *lst_a)
{
	t_list	*cur;
	t_list	*temp;
	int		sum_cost_cur;
	int		sum_cost_temp;

	cur = lst_a;
	temp = cur;
	while (cur)
	{
		sum_cost_cur = cur->push_cost + cur->target_node->push_cost;
		sum_cost_temp = temp->push_cost + temp->target_node->push_cost;
		if (sum_cost_cur < sum_cost_temp)
			temp = cur;
		cur = cur->next;
	}
	temp->cheapest = true;
	// printf("cheapest true: %d\n", temp->cheapest);
	// printf("cheapest value: %ld\n", temp->content);
	// printf("cheapest target node: %ld\n", temp->target_node->content);
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
    set_index(root_a);
	set_index(root_b);
	set_target_node(root_a, root_b);
	calc_push_cost(root_a, root_b);
	find_cheapest(root_a);
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