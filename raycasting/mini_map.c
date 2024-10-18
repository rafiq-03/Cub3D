/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:19:17 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/18 15:53:14 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void mini_(t_data *data)
{
	double x;
	double y;
	
	y = 0;
	while(y < 10 * TILE_SIZE)
	{
		x = 0;
		while(x < 14 * TILE_SIZE)
		{
			my_mlx_put_pixel(data, data->ft_3D, (t_coor){x, y}, get_rgba(196, 215, 255, 255));
			x++;
		}
		y++;
	}
	// printf ("height = %d, width = %d\n", data->map.heigth, data->map.width);
	
	y = data->player.coor.y / TILE_SIZE;
	x = data->player.coor.x / TILE_SIZE;
	// printf("y = %f, x = %f\n", y, x);
	double a = y + 5;
	y -= 5;
	while (y < a)
	{ 
		x = data->player.coor.x / TILE_SIZE;
		double z = x + 7;
			x -= 7;
		while (x < z)
		{
			if (x >= 0 && x < data->map.width && y >= 0 && y < data->map.heigth)
				draw_tile(data, (x + 7) * TILE_SIZE - data->player.coor.x,
					(y + 5)* TILE_SIZE - data->player.coor.y, data->map.grid[(int)y][(int)x], data->ft_3D);
			x++;
		}
		y++;
	}
	draw_player(data, (t_coor){7 * TILE_SIZE + fmod (data->player.coor.x, TILE_SIZE), 5 * TILE_SIZE + fmod (data->player.coor.y, TILE_SIZE)}, data->ft_3D);
	// ft_dda(data);
	// dda(data, (t_coor){7 * TILE_SIZE, 5 * TILE_SIZE}, (t_coor){7 * TILE_SIZE + cos(data->player.angle) * 30, 
	// 5 * TILE_SIZE + sin(data->player.angle) * 30}, get_rgba(255, 10, 0, 255), data->ft_3D);
	
}
