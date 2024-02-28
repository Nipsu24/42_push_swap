/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:14:45 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/28 16:52:07 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **lst)
{
	t_list	*temp;

	if (!(*lst) || !lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

int	free_stacks(t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
int	ft_perror(void)
{
	write(2, "Error\n", 6);
	return (0);
}


void	perror_free_exit(t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	*free_stack_exit(t_list **lst)
{
	free_stack(lst);
	exit (1);
}


t_list	*fill_stack_a(char **av, int i, t_list **stack_a)
{
	t_list		*stack_a_input;
	long int	nbr;

	stack_a_input = NULL;
	while (av[i])
	{
		stack_a_input = malloc(sizeof(t_list));
		if (!stack_a_input)
			(free_stack_exit(stack_a));
		nbr = ft_atol(av[i]);
		//printf("%ld\n", nbr);
		if (nbr > INT_MAX || nbr < INT_MIN)
			perror_free_exit(stack_a, &stack_a_input);
		stack_a_input->content = nbr;
		stack_a_input->next = NULL;
		ft_lstadd_back(stack_a, stack_a_input);
		i++;
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
