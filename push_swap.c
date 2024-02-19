/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:14:45 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/19 15:15:37 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char *av[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_a_input;

	i = 1;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[i], ' ');
		i--;
	}
	while (av[i])
	{
		if (!ft_check_input(av, i))
			print_error_exit(NULL, NULL);
		stack_a_input = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a_input->content = ft_atol(av[i]);
		stack_a->next = NULL;
		ft_lstadd_back(&stack_a, stack_a_input);
		i++;
	}
	if (is_sorted(stack_a))
		return (0);
	prep_to_sort(&stack_a, &stack_b);
	//for printing
	t_list *current = stack_a;
    while (current != NULL)
    {
        printf("%ld\n", current->content);
        current = current->next;
    }
	return (0);
}
