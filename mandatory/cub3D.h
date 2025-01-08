/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:54:40 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/08 20:13:00 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../utils/MLX42/include/MLX42/MLX42.h"
# include "../utils/libft/libft.h"
# define TILE_SIZE  32
# define DEGREE_0 0.0
# define DEGREE_90 1.5707963268
# define DEGREE_60 1.0471975512
# define DEGREE_180 M_PI
# define DEGREE_270 4.7123889804
# define WIDTH 1600
# define HEIGHT 1000

# define RAD 0.0174532925
# define DEGREE 0.034906585
# define SPEED 2

# define N_RAYS 1600

# define FOV 1.0471975512

# define RAY_ANGLE_INC 0.0006544985

typedef struct s_coor
{
	double	x;
	double	y;
}	t_coor;

typedef struct s_player
{
	t_coor		coor;
	double		angle;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		heigth;
}	t_map;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_color
{
	t_rgb		f;
	t_rgb		c;
	u_int16_t	flag;
}	t_color;

typedef struct s_texture
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	u_int16_t	flag;
}	t_texture;

typedef struct s_ray
{
	t_coor		wall_hit;
	double		x_texture;
	double		y_texture;
	double		distance;
	double		projection_distance;
	double		projection_column;
	double		top;
	double		bottom;
	int			color;
	int			flag;
}	t_ray;

typedef struct s_data
{
	t_list				*file_content;
	t_map				map;
	t_texture			textures;
	t_color				colors;
	int					header_end;
	t_player			player;
	mlx_t				*mlx;
	mlx_image_t			*ft_3d;
	t_ray				*rays;
	double				x_projection;
	mlx_texture_t		*texture1;
	mlx_texture_t		*texture2;
	mlx_texture_t		*texture3;
	mlx_texture_t		*texture4;
	mlx_image_t			*img1;
	mlx_image_t			*img2;
	mlx_image_t			*img3;
	mlx_image_t			*img4;
}	t_data;

void	check_requirements(int ac, char **av, t_data *data);
void	init_mlx_elements(t_data *data);

void	key_hooks(t_data *data);
void	cast_render(t_data *data);

void	ft_loop(void *dataa);
void	clean_all(t_data *data);

#endif
