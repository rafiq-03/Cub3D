/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:29:37 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/08 19:12:55 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	my_mlx_put_pixel(t_data *data, mlx_image_t *img, t_coor coor,
		u_int32_t color)
{
	if (coor.x >= 0 && coor.x < data->map.width * TILE_SIZE && coor.y >= 0
		&& coor.y < data->map.heigth * TILE_SIZE)
	{
		mlx_put_pixel(img, (int)coor.x, (int)coor.y, color);
	}
}

double	ft_normalizer(double angle)
{
	if (angle < 0)
		angle = 2 * M_PI + angle;
	else if (angle >= 2 * M_PI)
		angle = fmod(angle, 2 * M_PI);
	return (angle);
}

int	gett_rgba(uint8_t *color)
{
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | color[3]);
}
