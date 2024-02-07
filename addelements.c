/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addelements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:15:14 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/07 14:28:31 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char *av[])
{
	int		i;
	char	**split_res;

	i = 1;
	if (ac < 2)
	{
		printf("%s\n", av[0]);
		return (0);
	}
	if (ac == 2)
	{
		split_res = ft_split(av[i], ' ');
		i--;
		while (split_res[i])
		{
			if (!ft_check_input(split_res, i))
			{
				printf("Error");
				exit (1);
			}
			else 
			{
				printf("%s\n", split_res[i]);
				i++;
			}
		}
	}
	if (ac > 2)
		{
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
		}
	return (0);
}
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

int	input_is_nbr(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1])
		i++;
	while(av[i] && ft_isdigit_ps(av[i]))
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
			if (!ft_strcmp(av[i], av[j]) && i != j)
				return (1);
			j++;
		}
		i++;
	}
    return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
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
/*

	while (i < ac)
		{
			if ((ft_isdigit_ps(av[i]) == 1) || (ft_isdigit_ps(split_res[i]) == 1))
				return (0);
			else 
			{
			(printf("%s\n", argv[i]));
			(printf("%s\n", split_res[i]));
			}
			i++;
		}
	return (0);
}
*/

/*
typedef struct s_list
{
    void    *content;
    struct s_list *next;
} t_list;
*/


/*
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next)
		temp = temp -> next;
	temp -> next = new;
}

int main(int argc, char *argv[])
{
    int i;
    i = 1;
    t_list *root = NULL;

    if (argc < 2)
        return (0);
	if (argc == 2)
		argv = split_n_check_nbr(argv[i]);
    while (i < argc)
    {
        t_list *new_node = malloc(sizeof(t_list));
        if (!new_node)
            return (0);
        new_node->content = ft_strdup(argv[i]); // ft_atoi instead of strdrup ???
        if (!new_node->content)
        {
            free(new_node);
            return (0);
        }
        new_node->next = NULL;
        ft_lstadd_back(&root, new_node);
        i++;
    }
    //for printing
    t_list *current = root;
    while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }
    current = root;
    while (current != NULL)
    {
        t_list *temp = current;
        current = current->next;
        free(temp->content);
        free(temp);
    }
    return (0);
}

*/
/*if (argc == 2)*/
/*
char	**split_n_check_nbr(char *quote)
{
	int		i;
	char	**split_res;

	i = 0;
	split_res = ft_split(quote, ' ');
	while (split_res && split_res[i])
	{
		if (!ft_atoi(split_res[i]))
		{
			printf("Error");
			return (0);
		}
		else (printf("%s\n", split_res[i]));
		i++;
	}
	return (split_res);
}

*/