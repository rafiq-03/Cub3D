/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:26:27 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/08 19:44:32 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	draw_player(t_data *data, t_coor coor, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			my_mlx_put_pixel(data, img, (t_coor){coor.x + i - 3, coor.y + j
				- 3}, get_rgba(96, 86, 120, 255));
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
	while (++j < MINI_HEIGHT)
	{
		x = data->player.coor.x - 10 * TILE_SIZE;
		i = -1;
		while (++i < MINI_WIDTH)
		{
			if (space_or_wall(x, y, data->map) == 2)
				my_mlx_put_pixel(data, data->ft_3d, (t_coor){i, j},
					get_rgba(0, 0, 0, 255));
			else if (space_or_wall(x, y, data->map) == 1)
				my_mlx_put_pixel(data, data->ft_3d, (t_coor){i, j},
					get_rgba(246, 230, 203, 255));
			x++;
		}
		y++;
	}
	draw_player(data, (t_coor){10 * TILE_SIZE, 5 * TILE_SIZE}, data->ft_3d);
}
