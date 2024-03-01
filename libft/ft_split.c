/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:21:38 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/01 14:21:00 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_subcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] != 0 && s[i] != c)
		{
			count++;
			while (s[i] != 0 && s[i] != c)
				i++;
		}
		while (s[i] != 0 && s[i] == c)
			i++;
	}
	if (count == 0)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	return (count);
}

static char	**ft_free(char **result, size_t j)
{
	while (j > 0)
	{
		free(result[j - 1]);
		j--;
	}
	free(result);
	result = NULL;
	return (NULL);
}

static void	contains_empty_string(char *av[], size_t j)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			ft_free(av, j);
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

static char	**ft_writewords(char const *s, char c, char **strings)
{
	size_t	start;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	start = 0;
	while (s[i] != 0)
	{
		if (s[i] != 0 && s[i] != c)
		{
			start = i;
			while (s[i] != 0 && s[i] != c)
				i++;
			strings[j] = ft_substr(s, start, (i - start));
			if (strings[j] == 0)
				return (ft_free(strings, j));
			j++;
		}
		else
			i++;
	}
	strings[j] = 0;
	contains_empty_string(strings, j);
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;

	if (!s)
		return (0);
	strings = (char **) malloc (sizeof(char *) * (ft_subcount(s, c) + 1));
	if (strings == 0 || s == 0)
		return (NULL);
	return (ft_writewords(s, c, strings));
}
