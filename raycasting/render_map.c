/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:34:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/16 15:39:53 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
void	draw_tile(t_data *data, int	x, int y, char c)
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
				mlx_put_pixel(data->map.img, x + i, y + j , get_rgba(0, 0, 0, 255));
			else if (c == '0' || ft_strchr("NSEW", c))
				mlx_put_pixel(data->map.img, x + i, y + j , get_rgba(246, 230, 203, 255));
			j++;
		}
		i++;
	}
}

void	mini_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			draw_tile(data, x * TILE_SIZE, y * TILE_SIZE, data->map.grid[y][x]);
			x++;
		}
		y++;	
	}
	draw_player(data, data->player.coor);
	ft_dda(data);
}
