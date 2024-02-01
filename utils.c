/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:04:35 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/01 15:22:27 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"
/*
int	ft_isdigit(char *argv[], int i)
{
	if (argv[i] >= 48 && argv[i] <= 57)
		return (1);
	return (0);
}
*/


size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (ptr == 0)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (start + len > (ft_strlen(s)))
		len = (ft_strlen(s) - start);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (ptr == 0)
		return (NULL);
	if (len == 0)
		ptr[len] = '\0';
	while (len > 0)
	{
		ptr[i] = s[start];
		len--;
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

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
	return (NULL);
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

static int	ft_convertno(const char *str, int n, int minus)
{
	long int	number;
	long int	prenbr;

	prenbr = 0;
	number = 0;
	while (str[n] >= 48 && str[n] <= 57)
	{
		number *= 10;
		number += str[n] - 48;
		n++;
		if (prenbr > number)
		{
			if (minus > 0)
				return (0);
			else
				return (-1);
		}
		prenbr = number;
	}
	return (number);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	number;
	int	plus;

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
	number = ft_convertno(str, i, minus);
	if (minus == 1)
		return (-number);
	return (number);
}
