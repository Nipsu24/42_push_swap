/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:15:14 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/08 16:39:08 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*	j stores initial value of i in order to pass it
	further to other functions */
int	ft_check_input(char **av, int i)
{
	int j;

	j = i;
	while (av[i])
	{
		if (!input_is_nbr(av[i]))
			return (0);
		i++;
	}
	if (nbr_is_dupl(av, j))
			return (0);
	return (1);
}
