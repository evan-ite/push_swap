# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 16:51:38 by evan-ite          #+#    #+#              #
#    Updated: 2024/02/15 17:25:34 by elisevanite      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap
LIBFT = libft/libft.a
SRC = main.c stack.c operations.c smallsort.c algorithm.c algorithm_utlis.c

OBJ = $(SRC:.c=.o)

all: libft $(NAME)

$(NAME): libft $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) -C libft;

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) *.gch
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft
