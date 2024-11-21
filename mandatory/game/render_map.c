/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:34:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/21 17:55:27 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/*
	algorithm of raycasting 

	while (form first ray to last ray)
	{
		calculate ray angle :
			depend on the player's angle and FOV (60 degrees)
		cast ray depend on the ray angle
			+ calculate horizontal hit coor 
			{
				difine first A intersection;
				
				calculate distance;	
			}
			+ calculate virtical hit coor 
			{
				difine A first intersection;
	
				
				
				calculate distance;	
			}
			compare virtical distance and horizontal distance and choose the smallest distance 
	}
			
*/
void	draw_tile(t_data *data, int	x, int y, char c, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (c == '1')
				my_mlx_put_pixel(data, img, (t_coor){x + i, y + j}, get_rgba(0, 0, 0, 255));
				// my_mlx_put_pixel(data->map.img, x + i, y + j , get_rgba(0, 0, 0, 255));
			else if (c == '0' || ft_strchr("NSEW", c))
				// mlx_put_pixel(data->map.img, x + i, y + j , get_rgba(246, 230, 203, 255));
				my_mlx_put_pixel(data, img, (t_coor){x + i, y + j}, get_rgba(246, 230, 203, 255));
			j++;
		}
		i++;
	}
}

void render_background(t_data *data)
{
    int i = 0;
	int j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				mlx_put_pixel(data->ft_3D, j, i, get_rgba(62, 43, 43, 240));
			else
				mlx_put_pixel(data->ft_3D, j, i, get_rgba(123, 62, 11, 169));
			j++;
		}
		i++;
	}
}

void	cast_rays(t_data *data)
{
    render_background(data);
	mini_map(data);
	projection_3D(data);
}
