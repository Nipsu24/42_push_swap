# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:47:56 by mmeier            #+#    #+#              #
#    Updated: 2024/02/20 15:41:58 by mmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FILES = check_input_utils.c \
		check_input.c \
		lists_utils.c \
		prep_to_sort.c \
		push.c \
		rev_rotate.c \
		rotate.c \
		swap.c \
		utils.c \
		push_swap.c \

LIBFT = ./libft

OBJ = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(LIBFT)
	make -C libft
	$(CC) -o $(NAME) $(OBJ) -L$(LIBFT) -lft

all: $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re