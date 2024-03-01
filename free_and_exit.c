/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:01:45 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/01 15:10:06 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char	**av)
{
	int	j;

	j = 0;
	if (av[j] == NULL || av == NULL)
		return ;
	while (av[j])
	{
		free(av[j]);
		av[j] = NULL;
		j++;
	}
	free(av);
	av = NULL;
}

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
	if (lst)
		lst = NULL;
}

int	free_stacks(t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

void	perror_free_exit(t_list **stack_a, t_list **stack_b, int j, char **av)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	if (j == 0)
	{
		if (av)
		{
			free_array(av);
			av = NULL;
		}
	}
	exit (1);
}

void	free_stack_exit(t_list **lst, int j, char **av)
{
	free_stack(lst);
	if (j == 0)
	{
		free_array(av);
		av = NULL;
	}
	exit (1);
}
