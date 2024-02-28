/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:30:44 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/28 16:35:42 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sign(char c)
{
	if ((c == '+') || (c == '-'))
		return (1);
	return (0);
}

int	ft_isdigit_ps(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	input_is_nbr(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1])
		i++;
	while (av[i] && ft_isdigit_ps(av[i]))
		i++;
	if (av[i] && !ft_isdigit_ps(av[i]))
		return (0);
	return (1);
}

/*	ft_atol used for ruling out e.g. 000x duplicates */
int	nbr_is_dupl(char **av, int i)
{
	int	j;

	j = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (ft_atol(av[i]) == ft_atol(av[j]) && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
