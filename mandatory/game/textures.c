/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/04 16:44:24 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "game.h"
void	put_textures(t_data *data,t_ray *ray, mlx_image_t *img, int flag)
{
	int    i;

	i = ray->top;
	while(i < ray->bottom)
	{
		ray->y_texture = ((i - ray->top) / (ray->bottom - ray->top)) * img->height;
		if (i >= 0 && i < HEIGHT)
		{
			if ((int)ray->y_texture * img->width + (int)ray->x_texture <= img->height * img->width)
			{
                if (!flag)
                {
                        ray->color = gett_rgba(&img->pixels[(((int)ray->y_texture * img->width + (img->width - 1 - (int)ray->x_texture))) * 4]);
                }
                else
                    ray->color = gett_rgba(&img->pixels[(((int)ray->y_texture * img->width + (int)ray->x_texture)) * 4]);
                    
				mlx_put_pixel(data->ft_3d, data->x_projection  , i, ray->color);
			}
		}
		i++;
	}
}

void textures(t_data *data,t_ray *ray, mlx_image_t *img, int flag)
{
	if (ray->flag == 'h')
		ray->x_texture = (ray->Wall_hit.x / TILE_SIZE - floor(ray->Wall_hit.x / TILE_SIZE)) * img->width;
	else if (ray->flag == 'v')
		ray->x_texture = (ray->Wall_hit.y / TILE_SIZE - floor(ray->Wall_hit.y / TILE_SIZE)) * img->width;
	put_textures(data, ray, img, flag);
}

void	draw_columns(t_data *data, t_ray *ray, double angle)
{
	ray->distance *= cos(data->player.angle - angle);
	ray->projection_distance = WIDTH / 2 * tan(FOV / 2);
	ray->projection_column = ((TILE_SIZE * ray->projection_distance) / ray->distance) * 2;
	ray->top = (HEIGHT / 2) - (ray->projection_column / 2);
	ray->bottom = (HEIGHT / 2) + (ray->projection_column / 2);
	if ((sin(angle) <= 0 && ray->flag == 'h'))//----->top
		textures(data, ray, data->img1, 1);
	if ((sin(angle) >= 0 && ray->flag == 'h'))//buttom
		textures(data, ray, data->img2, 0);
	if ((cos(angle) >= 0 && ray->flag == 'v'))// ----->right
		textures(data, ray, data->img3, 1);
	if (cos(angle) <= 0  && ray->flag == 'v')// ----->left
		textures(data, ray, data->img4, 0);
}