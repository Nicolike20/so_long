# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nortolan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 14:20:58 by nortolan          #+#    #+#              #
#    Updated: 2021/11/02 12:15:03 by nortolan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
cc = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = so_long.c map_maker.c moving.c utils.c

OBJS = $(SRCS:%.c=%.o)

PHONY. = all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	#$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a
#$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
