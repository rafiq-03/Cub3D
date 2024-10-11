/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:54:40 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/10 13:16:21 by rmarzouk         ###   ########.fr       */
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

/*------------------------[ structs ]----------------------------------*/

typedef struct s_coor
{
	double	x;	
	double	y;
	
}	t_coor;

typedef struct s_map
{
	char **map;
	t_coor	player;
	
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
	t_list		*file_content;
	t_map		map;
	t_texture	textures;
	t_color		colors;
	int		 	header_end;
	// t_coor		coor;
	
	
}	t_data;



/*------------------------[ prototypes ]-------------------------------*/

/*--[ :: parsing :: ]--*/

void check_requirements(int ac, char **av, t_data *data);


/*--[ :: raycasting :: ]--*/


#endif
