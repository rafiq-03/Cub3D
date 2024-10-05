# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 15:54:37 by rmarzouk          #+#    #+#              #
#    Updated: 2024/10/05 16:35:12 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
MLX_FALGS=MLX42/build/libmlx42.a MLX42/build/libglfw3.a
LIBS = -framework Cocoa -framework OpenGL -framework IOKit
LIBFT_FLAGS = -L src/libft -lft

NAME = cub3D

PARSING_DIR = parsing/
S_PARSING= $(addprefix $(PARSING_DIR), ft_requirements.c\
								)

O_PARSING = $(S_PARSING:.c=.o)

all: $(NAME)

$(NAME): $(NAME).o $(O_PARSING)
	make -C src/libft
	$(CC) $(CFLAGS) $(MLX_FALGS) $(LIBS) $(LIBFT_FLAGS) $(NAME).o $(O_PARSING) -o $(NAME)

%.o:%.c cube3d.h
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	make fclean -C src/libft
	rm -f $(NAME).o
	rm -fr $(O_PARSING)

fclean: clean
	rm -f $(NAME)

re: fclean all
