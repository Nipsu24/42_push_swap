/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:30:26 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/26 15:42:52 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_lst(t_list **lst_a, t_list **lst_b)
{
	int	len;

	len = lst_len(*lst_a);
	if (len-- > 3 && !(is_sorted(*lst_a)))
		push_b(lst_a, lst_b);
	if (len-- > 3 && !(is_sorted(*lst_a)))
		push_b(lst_a, lst_b);
	while (len > 3)
	{
		prep_list_a(*lst_a, *lst_b);
		push_a_to_b(lst_a, lst_b);
		len--;
	}
	sort_three(lst_a);
	while (*lst_b)
	{
		prep_list_b(*lst_a, *lst_b);
		push_b_to_a(lst_a, lst_b);
	}
	set_index(*lst_a);
	sort_a_final(lst_a);
}
