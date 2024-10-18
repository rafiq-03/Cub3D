/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/18 15:30:36 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	dda(t_data *data, t_coor a, t_coor b, int color, mlx_image_t *img)
{
	int step;
	double dx;
	double dy;

	double xinc;
	double yinc;

	dy = b.y - a.y;
	dx = b.x - a.x;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	xinc = dx / step;
	yinc = dy / step;
	int i = 0;
	while (i <= step)
	{
		my_mlx_put_pixel(data, img,(t_coor){a.x , a.y}, color);
		a.x += xinc;
		a.y += yinc;
		i++;
	}
}
t_coor	first_h_inter(double angle, t_coor player)
{
	t_coor first_h;
	
	angle = ft_normalizer(angle);
	if (angle >= 0 && angle <= M_PI)// down 
		first_h.y = floor(player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;

	else if (angle > M_PI && angle < 2 * M_PI) // up
		first_h.y = floor(player.y / TILE_SIZE) * TILE_SIZE - 0.001;

	first_h.x = (first_h.y - player.y) / tan(angle) + player.x;

	return (first_h);
}

t_coor	first_v_inter(double angle, t_coor player)
{
	t_coor first_v;

	if (angle >= M_PI / 2 && angle <= 1.5 * M_PI)//left
		first_v.x = (int)(player.x / TILE_SIZE) * TILE_SIZE - 0.001;
	else if (angle >= 1.5 * M_PI || angle <= M_PI / 2)// right
		first_v.x = (int)(player.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	
	first_v.y = player.y + tan(angle) * (first_v.x - player.x);
	return (first_v);
}

t_coor h_wall_detect(t_map map, t_coor first, double angle)
{
	t_coor hit;
	int i;
	int	x;
	int y;

	angle = ft_normalizer(angle);
	i = 0;
	hit.x = first.x;
	hit.y = first.y;
	while (i <= map.heigth)
	{
		x = (int)(hit.x / TILE_SIZE);
		y = (int)((hit.y) / TILE_SIZE);
		if (x >= 0 && y >= 0 && x < map.width && y < map.heigth && map.grid[y][x] == '1')
			return (hit);
		if (angle >= 0 && angle < M_PI)// down
		{
			hit.y += TILE_SIZE;
			hit.x += (TILE_SIZE) / tan(angle);
			
		}
		else // up
		{
			hit.y -= TILE_SIZE;
			hit.x -= TILE_SIZE / tan(angle);
		}
		
		i++;
	}
	return (hit);
}

t_coor v_wall_detect(t_map map, t_coor first, double angle)
{
	t_coor hit;
	int i;
	int	x;
	int y;

	i = 0;
	hit.x = first.x;
	hit.y = first.y;
	while (i <= map.width)
	{
		x = (int)(hit.x / TILE_SIZE);
		y = (int)(hit.y / TILE_SIZE);
		if (x >= 0 && x < map.width && y >= 0 && y < map.heigth && map.grid[y][x] == '1')
			return (hit);
		if (angle > M_PI / 2 && angle < 1.5 * M_PI) // left
		{
			hit.x -= TILE_SIZE;
			hit.y -= TILE_SIZE * tan(angle);
		}
		else //if (angle > 1.5 * M_PI || angle < M_PI / 2) // right
		{
			hit.x += TILE_SIZE;
			hit.y += TILE_SIZE * tan(angle);
		}
		i++;
	}
	return (hit);
}

t_coor	ft_compare(t_coor player, t_coor h, t_coor v, t_ray *ray)
{
	double PH;
	double PV;

	PH = sqrt(pow(h.y - player.y, 2)+ pow(h.x - player.x, 2));
	PV = sqrt(pow(v.y - player.y, 2)+ pow(v.x - player.x, 2));

	if (PV <= PH)
	{
		ray->distance = PV;
		return (v);
	}
	else
	{		
		ray->distance = PH;
		return (h);
	}
}


void	ft_dda(t_data *data)
{
	t_coor first_h;
	t_coor first_v;

		
	// printf("rays number is %d\n", N_RAYS);
	data->rays = malloc(N_RAYS * sizeof(t_ray));
	double angle = data->player.angle - FOV / 2;
	int i = 0;
	
	while (i < N_RAYS)// casting rays depened of player angle
	{
		first_h = first_h_inter(angle, data->player.coor);
		first_v = first_v_inter(angle, data->player.coor);
		t_coor hit_h = h_wall_detect(data->map, first_h, angle);
		t_coor hit_v = v_wall_detect(data->map, first_v, angle);
		// t_coor small_d = ft_compare(data->player.coor, hit_h, hit_v);
		
		data->rays[i].Wall_hit = ft_compare(data->player.coor, hit_h, hit_v, &(data->rays[i]));
		dda(data, data->player.coor, data->rays[i].Wall_hit, get_rgba(10, 100, 10, 255), data->map.img);
		// printf("distance = %f\n", data->rays[i].distance);
		angle += RAY_ANGLE_INC;
		i++;
	}
	dda(data, data->player.coor, (t_coor){data->player.coor.x + cos(data->player.angle) * 50,
		data->player.coor.y + sin(data->player.angle) * 50}, get_rgba(255, 10, 0, 255), data->map.img);
	



		// first_h = first_h_inter(data->player.angle, data->player.coor);
		// first_v = first_v_inter(data->player.angle, data->player.coor);
		// t_coor hit_h = h_wall_detect(data->map, first_h, data->player.angle);
		// t_coor hit_v = v_wall_detect(data->map, first_v, data->player.angle);
		// t_coor small_d = ft_compare(data->player.coor, hit_h, hit_v);
		// dda(data, data->player.coor, hit_v, get_rgba(0, 110, 0, 255));
	
	// dda(data, data->player.coor, (t_coor){data->player.coor.x + cos(data->player.angle) * 70,
	// 	data->player.coor.y + sin(data->player.angle) * 70});

	
		
	// double angle = data->player.angle - 0.785398;
	
	// while (angle < data->player.angle + 0.785398)// castin rays depened of player angle
	// {
	// 	dda(data, data->player.coor, (t_coor){data->player.coor.x + cos(angle) * 100,
	// 	data->player.coor.y + sin(angle) * 100});
	// 	angle += 0.00872665;
	// }
}


