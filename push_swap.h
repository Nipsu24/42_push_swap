/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:39:08 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/20 14:45:01 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

long int	ft_atol(const char *str);
//char		*ft_strdup(const char *s1);
//size_t	ft_strlen(const char *s);
//char		*ft_substr(char const *s, unsigned int start, size_t len);
//char		**ft_split(char const *s, char c);
int			ft_check_input(char **av, int i);
int			input_is_nbr(char *av);
int			is_sign(char c);
int			ft_isdigit_ps(char c);
int			nbr_is_dupl(char **av, int i);
void		ft_putstr(char *s);
int			main(int ac, char *av[]);

typedef struct s_list
{
	int long		content;
	struct s_list	*next;
}					t_list;

void		ft_lstadd_back(t_list **lst, t_list *new);
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
void		sort_five(t_list **lst_a, t_list **lst_b);
int			is_sorted(t_list *lst);
t_list		*lowest(t_list *lst);
t_list		*highest(t_list *lst);
void		print_error_exit(void);
t_list		*fill_stack_a(char **av, int i, t_list **stack_a);
int			free_stacks(t_list **stack_a, t_list **stack_b);
t_list		*fill_stack_b(t_list **stack_b);

#endif
