/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:14:45 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/20 14:44:14 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_error_exit(void)
{
	ft_putstr("Error\n");
	exit (1);
}

int	free_stacks(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	if (*stack_b)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	return (0);
}

t_list	*fill_stack_a(char **av, int i, t_list **stack_a)
{
	t_list	*stack_a_input;

	while (av[i])
	{
		stack_a_input = malloc(sizeof(t_list));
		if (!stack_a_input)
			return (0);
		stack_a_input->content = ft_atol(av[i]);
		stack_a_input->next = NULL;
		ft_lstadd_back(stack_a, stack_a_input);
		i++;
	}
	return (*stack_a);
}

t_list	*fill_stack_b(t_list **stack_b)
{
	*stack_b = malloc(sizeof(t_list));
	if (!*stack_b)
		return (0);
	return (*stack_b);
}

int	main(int ac, char *av[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[i], ' ');
		i--;
	}
	if (!ft_check_input(av, i))
		print_error_exit();
	stack_a = fill_stack_a(av, i, &stack_a);
	stack_b = fill_stack_b(&stack_b);
	if (is_sorted(stack_a))
		return (free_stacks(&stack_a, &stack_b));
	prep_to_sort(&stack_a, &stack_b);
	//for printing
	// t_list *current = stack_a;
    // while (current != NULL)
    // {
    //     printf("%ld\n", current->content);
    //     current = current->next;
    // }
	return (free_stacks(&stack_a, &stack_b));
}