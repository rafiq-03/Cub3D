/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:34:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/04 16:44:16 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				mlx_put_pixel(data->ft_3d, j, i, get_rgba(data->colors.c.r,
						data->colors.c.g, data->colors.c.b, 255));
			else
				mlx_put_pixel(data->ft_3d, j, i, get_rgba(data->colors.f.r,
						data->colors.f.g, data->colors.f.b, 255));
			j++;
		}
		i++;
	}
}

t_coor	wall_detect(t_map map, t_coor first, double angle, char flag)
{
	t_coor	hit;
	int		i;
	int		x;
	int		y;

	angle = ft_normalizer(angle);
	i = 0;
	hit = first;
	while (i <= map.heigth || i <= map.width)
	{
		x = (int)(hit.x / TILE_SIZE);
		y = (int)((hit.y) / TILE_SIZE);
		if (x >= 0 && y >= 0 && x < map.width
			&& y < map.heigth && map.grid[y][x] == '1')
			return (hit);
		if (flag == 'h')
			ft_horizontal(&hit, angle);
		else if (flag == 'v')
			ft_vertical(&hit, angle);
		i++;
	}
	return (hit);
}

void	cast_ray(t_data *data, double angle, int i)
{
	t_coor	hit_h;
	t_coor	hit_v;

	hit_h = first_h_inter(angle, data->player.coor);
	hit_v = first_v_inter(angle, data->player.coor);
	hit_h = wall_detect(data->map, hit_h, angle, 'h');
	hit_v = wall_detect(data->map, hit_v, angle, 'v');
	data->rays[i].Wall_hit = ft_compare(data->player.coor,
			hit_h, hit_v, &(data->rays[i]));
}

void	cast_render(t_data *data)
{
	double	angle;
	int		i;

	render_background(data);
	i = 0;
	data->x_projection = 0;
	data->rays = malloc(N_RAYS * sizeof(t_ray));
	if (!data->rays)
		return ;
	angle = data->player.angle - FOV / 2;
	while (i < N_RAYS)
	{
		cast_ray(data, angle, i);
		draw_columns(data, &data->rays[i], angle);
		data->x_projection++;
		angle += RAY_ANGLE_INC;
		i++;
	}
	free (data->rays);
}
