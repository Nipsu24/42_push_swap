/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:14:45 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/08 15:24:36 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char *av[])

{
	int	i;

	i = 1;
	if (ac < 2)
	{
		printf("%s\n", av[0]);
		return (0);
	}
	if (ac == 2)
	{
		av = ft_split(av[i], ' ');
		i--;
	}
	while (av[i])
	{
		if (!ft_check_input(av, i))
		{
			printf("Error");
			exit (1);
		}
		else
		{
			printf("%s\n", av[i]);
			i++;
		}
	}
	return (0);
}
