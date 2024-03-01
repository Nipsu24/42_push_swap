/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:14:45 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/01 15:14:44 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_stack_a(char **av, int i, t_list **stack_a)
{
	t_list		*stack_a_input;
	long int	nbr;
	int			j;

	j = i;
	stack_a_input = NULL;
	while (av[i])
	{
		stack_a_input = malloc(sizeof(t_list));
		if (!stack_a_input)
			(free_stack_exit(stack_a, j, av));
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			perror_free_exit(stack_a, &stack_a_input, j, av);
		stack_a_input->content = nbr;
		stack_a_input->next = NULL;
		ft_lstadd_back(stack_a, stack_a_input);
		i++;
	}
	if (j == 0)
	{
		free_array(av);
		av = NULL;
	}
	return (*stack_a);
}

int	main(int ac, char *av[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[i], ' ');
		i--;
	}
	if (!ft_check_input(av, i))
		return (ft_perror());
	stack_a = fill_stack_a(av, i, &stack_a);
	if (is_sorted(stack_a))
		return (free_stacks(&stack_a, &stack_b));
	prep_to_sort(&stack_a, &stack_b);
	return (free_stacks(&stack_a, &stack_b));
}
