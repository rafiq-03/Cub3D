/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:54:40 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/09 15:04:33 by rmarzouk         ###   ########.fr       */
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
	uint16_t	flag;
} t_texture;


typedef struct s_data
{
	t_list		*file_content;
	char		**map;
	t_texture	textures;
	t_color		colors;
	// t_coor		coor;
	
	
}	t_data;



/*------------------------[ prototypes ]-------------------------------*/

/*--[ :: parsing :: ]--*/

void check_requirements(int ac, char **av, t_data *data);

void	add_texture(char **texture, char *line, u_int16_t *flag);
void	clean_textures(t_texture *textures);
void	fill_textures(t_data *data);

void	fill_colors(t_data *data);

/*--[ :: raycasting :: ]--*/


#endif
