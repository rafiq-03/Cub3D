/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/25 11:35:27 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "game.h"

void textures(t_data *data,t_ray *ray, mlx_image_t *img, int flag)
{
	double x_texture;
	double y_texture;
	int i;
	int color;

	// x_of_texture = 0;
	// x_texture = (ray->Wall_hit.y / TILE_SIZE - floor(ray->Wall_hit.y / TILE_SIZE)) * data->img1->height;
	i = ray->top;
	if (ray->flag == 'h')
		x_texture = (ray->Wall_hit.x / TILE_SIZE - floor(ray->Wall_hit.x / TILE_SIZE)) * img->width;
	else if (ray->flag == 'v')
		x_texture = (ray->Wall_hit.y / TILE_SIZE - floor(ray->Wall_hit.y / TILE_SIZE)) * img->width;
	while(i < ray->bottom)
	{
		y_texture = ((i - ray->top) / (ray->bottom - ray->top)) * img->height;
		// printf("x-->%d\n", img->width);
		// printf("y-->%f\n", y_texture);
		if (i >= 0 && i < HEIGHT)
		{
			if ((int)y_texture * img->width + (int)x_texture <= img->height * img->width)
			{
                if (!flag)
                {
                        color = gett_rgba(&img->pixels[(((int)y_texture * img->width + (img->width - (int)x_texture))) * 4]);
                }
                else
                    color = gett_rgba(&img->pixels[(((int)y_texture * img->width + (int)x_texture)) * 4]);
                    
				mlx_put_pixel(data->ft_3D, data->x_projection  , i, color);
			}
			// mlx_put_pixel(data->ft_3D,data->x_projection , i, get_rgba(255,255,255,255));
		}
		i++;
	}
}
void	draw_columns(t_data *data, t_ray *ray, double angle)
{
	ray->distance *= cos(data->player.angle - angle);
	ray->projection_distance = WIDTH / 2 * tan(FOV / 2);
	ray->projection_column = ((TILE_SIZE * ray->projection_distance) / ray->distance) * 2;
	ray->top = (HEIGHT / 2) - (ray->projection_column / 2);
	ray->bottom = (HEIGHT / 2) + (ray->projection_column / 2);
	printf("distance_column = %f\n", ray->projection_column);
    if(ray->projection_column >= 2000)
        data->rotate_angle = 3 * DEGREE;
    else if(data->tmp_column_height >= 1600)
        data->rotate_angle = 2.5 * DEGREE;
    else if(data->tmp_column_height >= 1200)
        data->rotate_angle = 2 * DEGREE;
    else if(data->tmp_column_height >= 800)
        data->rotate_angle = 1.5 * DEGREE;
	if ((sin(angle) <= 0 && ray->flag == 'h'))//----->top
		textures(data, ray, data->img1, 1);
	if ((sin(angle) >= 0 && ray->flag == 'h'))//buttom
		textures(data, ray, data->img2, 0);
	if ((cos(angle) >= 0 && ray->flag == 'v'))// ----->right
		textures(data, ray, data->img3, 1);
	if (cos(angle) <= 0  && ray->flag == 'v')// ----->left
		textures(data, ray, data->img4, 0);
}

void	projection_3D(t_data *data)// render walls
{
	double angle;
	int i;
	
	angle = data->player.angle - FOV / 2;
	i = 0;
	data->x_projection = 0;
	while (i < N_RAYS)// casting rays depened of player angle
	{
		draw_columns(data, &data->rays[i], angle);
		data->x_projection++;
		angle += RAY_ANGLE_INC;
		i++;
	}
}
