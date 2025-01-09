# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 15:54:37 by rmarzouk          #+#    #+#              #
#    Updated: 2025/01/09 17:54:21 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 #-fsanitize=address
MLX_FALGS=utils/MLX42/build/libmlx42.a utils/MLX42/build/libglfw3.a
LIBS = -framework Cocoa -framework OpenGL -framework IOKit
LIBFT_FLAGS = -L utils/libft -lft

NAME = cub3D
NAME_B = cub3D_bonus

PARSING_DIR = mandatory/parsing/
PARSING_DIR_B = bonus/parsing/
S_PARSING = $(addprefix $(PARSING_DIR), ft_requirements.c\
									ft_textures.c\
									ft_colors.c\
									ft_map.c\
									ft_utils.c\
									ft_map_utils.c\
								)
S_PARSING_B = $(addprefix $(PARSING_DIR_B), ft_requirements_bonus.c\
									ft_textures_bonus.c\
									ft_colors_bonus.c\
									ft_map_bonus.c\
									ft_utils_bonus.c\
									ft_map_utils_bonus.c\
								)

O_PARSING = $(S_PARSING:.c=.o)
O_PARSING_B = $(S_PARSING_B:.c=.o)

GAME_DIR = mandatory/game/
GAME_DIR_B = bonus/game/
S_GAME= $(addprefix $(GAME_DIR), 			init_mlx.c\
											cast_render.c \
											hooks.c \
											textures.c \
											utils.c\
											cast_utils.c\
								)
S_GAME_B= $(addprefix $(GAME_DIR_B), 			init_mlx_bonus.c\
											cast_render_bonus.c \
											hooks_bonus.c \
											textures_bonus.c \
											utils_bonus.c\
											cast_utils_bonus.c\
											map_bonus.c\
								)

O_GAME = $(S_GAME:.c=.o)
O_GAME_B = $(S_GAME_B:.c=.o)

all: $(NAME)

$(NAME): mandatory/$(NAME).o $(O_PARSING) $(O_GAME)
	make -C utils/libft
	$(CC) $(CFLAGS) $(MLX_FALGS) $(LIBS) $(LIBFT_FLAGS) mandatory/$(NAME).o $(O_GAME) $(O_PARSING) -o $(NAME)

%.o:%.c mandatory/$(NAME).h bonus/$(NAME_B).h
	$(CC) -c $(CFLAGS) $< -o $@

bonus: $(NAME_B)
		
$(NAME_B): bonus/$(NAME_B).o $(O_PARSING_B) $(O_GAME_B)
	make -C utils/libft
	$(CC) $(CFLAGS) $(MLX_FALGS) $(LIBS) $(LIBFT_FLAGS) bonus/$(NAME_B).o $(O_GAME_B) $(O_PARSING_B) -o $(NAME_B)
clean:
	make fclean -C utils/libft
	rm -f mandatory/$(NAME).o
	rm -f bonus/$(NAME_B).o
	rm -fr $(O_PARSING) $(O_GAME)
	rm -fr $(O_PARSING_B) $(O_GAME_B)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_B)

re: fclean all
