/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:14:45 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/16 13:52:44 by mmeier           ###   ########.fr       */
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
	t_list *root = NULL;
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
		/*else
		{
			printf("%s\n", av[i]);
			i++;
		}*/
		t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = ft_atol(av[i]);
		/*if (!stack_a->content)
		{
			free(stack_a);
			return (0);
		}*/
		stack_a->next = NULL;
		ft_lstadd_back(&root, stack_a);
		i++;
	}
	//for printing
	t_list *current = root;
    while (current != NULL)
    {
        printf("%ld\n", current->content);
        current = current->next;
    }
	if (is_sorted(root))
		return ;  /////to be updated still!!
	/*
    current = root;
    while (current != NULL)
    {
        t_list *temp = current;
        current = current->next;
        free(temp->content);
        free(temp);
	}
	*/
	return (0);
}
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
