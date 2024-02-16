/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:17:56 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/16 13:38:45 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*highest(t_list *lst)
{
	t_list	*cur;
	t_list	*highest;

	cur = lst;
	highest = cur;
	if (!lst)
		return (NULL);
	while (cur)
	{
		if (cur->content > highest->content)
			highest = cur;
		cur = cur->next;
	}
	return (highest);
}

t_list	*lowest(t_list *lst)
{
	t_list	*cur;
	t_list	*lowest;

	cur = lst;
	lowest = cur;
	if (!lst)
		return (NULL);
	while (cur)
	{
		if (cur->content < lowest->content)
			lowest = cur;
		cur = cur->next;
	}
	return (lowest);
}

int	is_sorted(t_list *lst)
{
	t_list	*after;

	after = lst->next;
	while (lst && after)
	{
		if (lst->content > after->content)
			return (0);
		lst = lst->next;
		after = after->next;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int	i;

	i = 1;
	t_list *root = NULL;
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
    //t_list *current = root;
    // while (current != NULL)
    // {
    //     printf("%ld\n", current->content);
    //     current = current->next;
    // }
    printf("%s\n", "is sorted:");
    //printf("%d\n", is_sorted(root));
		// printf("%s\n", "is highest:");	/////testing highest////
    	// t_list *current = highest(root);
        // printf("%ld\n", current->content);
	printf("%s\n", "is lowest:");	/////testing lowest////
    t_list *current = lowest(root);
    printf("%ld\n", current->content);
    return (0);
}


