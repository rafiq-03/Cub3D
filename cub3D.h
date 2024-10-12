/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:54:40 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/12 13:47:57 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

/*------------------------[ includes ]----------------------------------*/

#include <unistd.h>//
#include <stdio.h> // for testing
#include <fcntl.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "src/libft/libft.h"


#define BOX  32

/*------------------------[ structs ]----------------------------------*/

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_coor
{
	double	x;	
	double	y;
	
}	t_coor;

typedef struct s_player
{
	t_coor		coor;// coordinates of player with pixels
	t_pos		pos;// wher the player  existe depend of its coordinates// by position of the player in map
	mlx_image_t *img;// img of player
	char		direction;// the first derection that player show it
	
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width; // width of map
	int		heigth;// height of map
	mlx_image_t *img;// image of map
}	t_map;

typedef	struct s_rgb
{
	int	r;
	int	g;
	int	b;
} t_rgb;

typedef struct s_color
{
	t_rgb		F;
	t_rgb		C;
	u_int16_t	flag;
} t_color;

typedef struct s_texture
{
	char		*NO;
	char		*SO;
	char		*EA;
	char		*WE;
	u_int16_t	flag;
} t_texture;


typedef struct s_data
{
	t_list		*file_content;// content from map's file
	t_map		map;// struct of infos of map
	t_texture	textures;// textures from file
	t_color		colors;// colors from file
	int		 	header_end; // when I finish to extract colors and colors i pust this flag to it
	t_player	player; // player information
	mlx_t		*mlx;// mlx variable
	mlx_image_t	*mm_backroud;// if we need background
	mlx_key_data_t keys; // key hooks
	
}	t_data;



/*------------------------[ prototypes ]-------------------------------*/

/*--[ :: parsing :: ]--*/

void check_requirements(int ac, char **av, t_data *data);


/*--[ :: raycasting :: ]--*/


#endif
