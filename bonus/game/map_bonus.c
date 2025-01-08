/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:26:27 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/08 20:54:53 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	draw_player(t_data *data, t_coor coor)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			mlx_put_pixel(data->ft_3d, coor.x + i - 3,
				coor.y + j - 3, get_rgba(96, 86, 120, 255));
			j++;
		}
		i++;
	}
}

int	space_or_wall(double x, double y, t_map map)
{
	if (x >= 0 && x < (map.width * TILE_SIZE)
		&& y >= 0 && y < (map.heigth * TILE_SIZE))
	{
		if (map.grid[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '0'
			|| ft_strchr("NSEW", map.grid[(int)(y /
				TILE_SIZE)][(int)(x / TILE_SIZE)]))
			return (1);
		else if (map.grid[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
			return (2);
	}
	return (0);
}

void	mini_map(t_data *data)
{
	double	x;
	double	y;
	int		i;
	int		j;

	j = -1;
	y = data->player.coor.y - 5 * TILE_SIZE;
	while (++j < TILE_SIZE * 10)
	{
		x = data->player.coor.x - 5 * TILE_SIZE;
		i = -1;
		while (++i < TILE_SIZE * 10)
		{
			if (space_or_wall(x, y, data->map) == 2)
				mlx_put_pixel(data->ft_3d, i, j, get_rgba(0, 0, 0, 255));
			else if (space_or_wall(x, y, data->map) == 1)
				mlx_put_pixel(data->ft_3d, i, j, get_rgba(246, 230, 203, 255));
			else
				mlx_put_pixel(data->ft_3d, i, j, get_rgba(100, 100, 100, 255));
			x++;
		}
		y++;
	}
	draw_player(data, (t_coor){5 * TILE_SIZE, 5 * TILE_SIZE});
}
