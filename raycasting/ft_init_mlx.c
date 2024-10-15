/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:31:30 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/15 17:44:03 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"


void	my_mlx_put_pixel(t_data *data, t_coor coor, u_int32_t color)
{
	if (coor.x >= 0 && coor.x < data->map.width * TILE_SIZE && coor.y >= 0 && coor.y < data->map.heigth * TILE_SIZE)
	{
		mlx_put_pixel(data->map.img, (int) coor.x,(int) coor.y, color);
	}
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	init_mlx_elements(t_data *data)
{
	/*
		player		img
		map			img
		mlx pointer;
	*/
	data->mlx = mlx_init(data->map.width * BOXE, data->map.heigth * BOXE, "CUB3D", false);
	if (!data->mlx)
	{
		ft_strerr("failed to create mlx pointer");
		return ;
	}
	// data->ft_3D = mlx_new_image(data->mlx, data->map.width * BOXE , data->map.heigth * BOXE);
	// if (!data->ft_3D)
	// {
	// 	ft_strerr("3d vue's image error");
	// 	exit(EXIT_FAILURE);
	// }
	data->map.img = mlx_new_image(data->mlx, data->map.width * TILE_SIZE, data->map.width * TILE_SIZE);
	if (!data->map.img)
	{
		ft_strerr("map's img error");
		exit(EXIT_FAILURE);
	}
	mlx_image_to_window(data->mlx, data->map.img, 0 , 0);
}

double ft_normalizer(double angle)
{
	double	normalize;
	
	normalize = fmod(angle, 2 * M_PI);// need to check it later
	if (normalize < 0)
		normalize = 2 * M_PI - normalize;
	return (normalize);
}
