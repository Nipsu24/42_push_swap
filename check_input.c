/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:15:14 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/14 11:01:34 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	j stores initial value of i in order to pass it
	further to other functions */
int	ft_check_input(char **av, int i)
{
	int	j;

	j = i;
	while (av[i])
	{
		if (!input_is_nbr(av[i]))
			return (0);
		i++;
	}
	if (contains_empty_string(av, j))
		return (0);
	if (nbr_is_dupl(av, j))
		return (0);
	if (!in_range(av, j))
		return (0);
	return (1);
}

int	in_range(char **av, int i)
{
	long int	num;

	num = 0;
	while (av[i] != NULL)
	{
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	contains_empty_string(char *av[], int i)
{
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_perror(void)
{
	write(2, "Error\n", 6);
	return (0);
}
