/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:04:35 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/01 15:29:14 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_convertno(const char *str, int n)
{
	long int	number;
	int			count;

	number = 0;
	count = 0;
	while (str[n] >= 48 && str[n] <= 57 && count < 11)
	{
		number *= 10;
		number += str[n] - 48;
		n++;
		count++;
	}
	return (number);
}

long int	ft_atol(const char *str)
{
	int			i;
	int			minus;
	long int	number;
	int			plus;

	minus = 0;
	plus = 0;
	number = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		if (str[i] == '+')
			plus++;
		if (minus + plus > 1)
			return (0);
		i++;
	}
	number = ft_convertno(str, i);
	if (minus == 1)
		return (-number);
	return (number);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
