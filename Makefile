# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 15:54:37 by rmarzouk          #+#    #+#              #
#    Updated: 2024/10/05 11:41:54 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FALGS=MLX42/build/libmlx42.a MLX42/build/libglfw3.a
LIBS = -framework Cocoa -framework OpenGL -framework IOKit
# LIBFT = ./Libft/libft.a

NAME = cube3d


all: $(NAME)

$(NAME): $(NAME).o
	$(CC) $(CFLAGS) $(MLX_FALGS) $(LIBS) $(NAME).o -o $(NAME)

%.o:%.c cube3d.h
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	rm -f $(NAME).o

fclean: clean
	rm -f $(NAME)

re: fclean all
