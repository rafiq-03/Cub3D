/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/07 17:10:45 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	getcolor_from_texture(t_ray **ray, mlx_texture_t *texture, int flag)
{
	if (!flag)
	{
		(*ray)->color = gett_rgba(&texture->pixels
			[(((int)(*ray)->y_texture * texture->width
						+ (texture->width - 1
							- (int)(*ray)->x_texture))) * 4]);
	}
	else
		(*ray)->color = gett_rgba(&texture->pixels
			[(((int)(*ray)->y_texture * texture->width
						+ (int)(*ray)->x_texture)) * 4]);
}

void	put_textures(t_data *data, t_ray *ray, mlx_texture_t *texture, int flag)
{
	int	i;

	(void)data;
	i = ray->top;
	while (i < ray->bottom)
	{
		ray->y_texture = ((i - ray->top) / (ray->bottom - ray->top))
			* texture->height;
		if (i >= 0 && i < HEIGHT)
		{
			if ((int)ray->y_texture * texture->width
				+ (int)ray->x_texture <= texture->height * texture->width)
				getcolor_from_texture(&ray, texture, flag);
			mlx_put_pixel(data->ft_3d, data->x_projection, i, ray->color);
		}
		i++;
	}
}

void	textures(t_data *data, t_ray *ray, mlx_texture_t *texture, int flag)
{
	if (ray->flag == 'h')
		ray->x_texture = (ray->wall_hit.x / TILE_SIZE - floor(ray->wall_hit.x
					/ TILE_SIZE)) * texture->width;
	else if (ray->flag == 'v')
		ray->x_texture = (ray->wall_hit.y / TILE_SIZE - floor(ray->wall_hit.y
					/ TILE_SIZE)) * texture->width;
	put_textures(data, ray, texture, flag);
}

void	draw_columns(t_data *data, t_ray *ray, double angle)
{
	ray->distance *= cos(data->player.angle - angle);
	ray->projection_distance = WIDTH / (2 * tan(FOV / 2));
	ray->projection_column = ((TILE_SIZE * ray->projection_distance)
			/ ray->distance);
	ray->top = (HEIGHT / 2) - (ray->projection_column / 2);
	ray->bottom = (HEIGHT / 2) + (ray->projection_column / 2);
	if ((sin(angle) <= 0 && ray->flag == 'h'))
		textures(data, ray, data->texture1, 1);
	if ((sin(angle) >= 0 && ray->flag == 'h'))
		textures(data, ray, data->texture2, 0);
	if ((cos(angle) >= 0 && ray->flag == 'v'))
		textures(data, ray, data->texture3, 1);
	if (cos(angle) <= 0 && ray->flag == 'v')
		textures(data, ray, data->texture4, 0);
}
