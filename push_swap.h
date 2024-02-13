/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:39:08 by mmeier            #+#    #+#             */
/*   Updated: 2024/02/13 14:54:51 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>

long int	ft_atol(const char *str);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
int			ft_check_input(char **av, int i);
int			input_is_nbr(char *av);
int			is_sign(char c);
int			ft_isdigit_ps(char c);
int			nbr_is_dupl(char **av, int i);
void		ft_putstr(char *s);

typedef struct s_list
{
	int long		content;
	struct s_list	*next;
}	t_list;

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

#endif
