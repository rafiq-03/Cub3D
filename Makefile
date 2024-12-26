# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 15:54:37 by rmarzouk          #+#    #+#              #
#    Updated: 2024/12/26 16:52:15 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 
MLX_FALGS=utils/MLX42/build/libmlx42.a utils/MLX42/build/libglfw3.a
LIBS = -framework Cocoa -framework OpenGL -framework IOKit
LIBFT_FLAGS = -L utils/libft -lft

NAME = cub3D
NAME_B = cub3D_bonus

PARSING_DIR = mandatory/parsing/
S_PARSING= $(addprefix $(PARSING_DIR), ft_requirements.c\
									ft_textures.c\
									ft_colors.c\
									ft_map.c\
									ft_utils.c\
									ft_map_utils.c\
								)

O_PARSING = $(S_PARSING:.c=.o)

GAME_DIR = mandatory/game/
S_GAME= $(addprefix $(GAME_DIR), 			init_mlx.c\
											render.c \
											hooks.c \
											textures.c \
											utils.c\
											raycasting.c\
											map.c\
								)

O_GAME = $(S_GAME:.c=.o)

all: $(NAME)

$(NAME): mandatory/$(NAME).o $(O_PARSING) $(O_GAME)
	make -C utils/libft
	$(CC) $(CFLAGS) $(MLX_FALGS) $(LIBS) $(LIBFT_FLAGS) mandatory/$(NAME).o $(O_GAME) $(O_PARSING) -o $(NAME)

%.o:%.c mandatory/$(NAME).h
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	make fclean -C utils/libft
	rm -f mandatory/$(NAME).o
	rm -fr $(O_PARSING) $(O_GAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
