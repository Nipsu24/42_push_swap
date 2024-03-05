# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:47:56 by mmeier            #+#    #+#              #
#    Updated: 2024/03/05 13:16:09 by mmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FILES = check_input_utils.c \
		check_input.c \
		lists_utils_1.c \
		lists_utils_2.c \
		prep_list_a.c \
		prep_to_sort.c \
		push_a_to_b.c \
		push_b_to_a.c \
		push_swap.c \
		push.c \
		rev_rotate.c \
		rotate.c \
		swap.c \
		utils.c \
		free_and_exit.c

LIBFT = ./libft

OBJ = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(LIBFT)
	make -C libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L$(LIBFT) -lft

fsanitize: 
	$(CC) -o $(NAME) $(FILES) -L$(LIBFT) -lft -g -fsanitize=address -static-libsan 

all: $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
