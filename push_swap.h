/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:39:08 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/07 10:21:26 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

long int	ft_atol(const char *str);
int			ft_check_input(char **av, int i);
int			input_is_nbr(char *av);
int			is_sign(char c);
int			ft_isdigit_ps(char c);
int			nbr_is_dupl(char **av, int i);
void		ft_putstr(char *s);
int			main(int ac, char *av[]);

typedef struct s_list
{
	int				content;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_list	*next;
	struct s_list	*target_node;
}					t_list;

void		ft_lstadd_back(t_list **lst, t_list *new_node);
t_list		*ft_lstlast(t_list *lst);
void		swap_a(t_list **lst);
void		swap_b(t_list **lst);
void		swap_ab(t_list **lst_a, t_list **lst_b);
void		push_a(t_list **lst_a, t_list **lst_b);
void		push_b(t_list **lst_a, t_list **lst_b);
void		rotate_a(t_list **lst_a);
void		rotate_b(t_list **lst_b);
void		rotate_ab(t_list **lst_a, t_list **lst_b);
void		rev_rotate_a(t_list **lst_a);
void		rev_rotate_b(t_list **lst_b);
void		rev_rotate_ab(t_list **lst_a, t_list **lst_b);
int			lst_len(t_list *lst);
void		prep_to_sort(t_list **lst_a, t_list **lst_b);
void		sort_two(t_list **lst_a);
void		sort_three(t_list **lst_a);
int			is_sorted(t_list *lst);
t_list		*lowest(t_list *lst);
t_list		*highest(t_list *lst);
int			ft_perror(void);
t_list		*fill_stack_a(char **av, int i, t_list **stack_a);
void		set_index(t_list *lst);
void		set_target_node(t_list *lst_a, t_list *lst_b);
void		calc_push_cost(t_list *lst_a, t_list *lst_b);
void		find_cheapest(t_list *lst_a);
void		prep_list_a(t_list *lst_a, t_list *lst_b);
void		push_a_to_b(t_list **lst_a, t_list **lst_b);
void		rotate_both(t_list **lst_a, t_list **lst_b, t_list *cheapest);
void		rev_rotate_both(t_list **lst_a, t_list **lst_b, t_list *cheapest);
void		final_prep_push(t_list **lst, t_list *cheapest, char stack);
void		prep_list_b(t_list *lst_a, t_list *lst_b);
void		set_target_b(t_list *lst_a, t_list *lst_b);
void		push_b_to_a(t_list **lst_a, t_list **lst_b);
void		sort_a_final(t_list **lst_a);
void		sort_lst(t_list **lst_a, t_list **lst_b);
t_list		*get_cheapest(t_list *lst);
void		free_stack(t_list **lst);
int			free_stacks(t_list **stack_a, t_list **stack_b);
void		perror_free_exit(t_list **stack_a, t_list **stack_b,
				int j, char **av);
void		free_stack_exit(t_list **lst, int j, char **av);
void		free_array(char	**av);
int			contains_empty_string(char *av[], int size);
int			in_range(char **av, int i);

#endif
