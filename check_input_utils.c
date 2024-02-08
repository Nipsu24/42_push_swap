/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:30:44 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/08 16:41:10 by mmeier           ###   ########.fr       */
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

/*	if strcmp == 0 strings are identical, 
	therefore nbr_is_dupl is true */
int	nbr_is_dupl(char **av, int i)
{
	int	j;

	j = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (!ft_strcmp_ps(av[i], av[j]) && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strcmp_ps(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] && s2[i] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
