/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/15 17:40:45 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	dda(t_data *data, t_coor a, t_coor b)
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
		my_mlx_put_pixel(data, (t_coor){a.x , a.y}, get_rgba(255, 110, 0, 255));
		a.x += xinc;
		a.y += yinc;
		i++;
	}
}
t_coor	first_h_inter(double angle, t_coor player)
{
	t_coor first_h;

	if (angle >= 0 && angle <= M_PI)// down 
		first_h.y = (int)(player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;

	else if (angle > M_PI && angle < 2 * M_PI) // up
		first_h.y = (int)(player.y / TILE_SIZE) * TILE_SIZE - 1;

	first_h.x = (first_h.y - player.y) / tan(angle) + player.x;

	return (first_h);
}

t_coor	first_v_inter(double angle, t_coor player)
{
	t_coor first_v;

	if (angle > M_PI / 2 && angle < 1.5 * M_PI)//left
		first_v.x = (int)(player.x / TILE_SIZE) * TILE_SIZE - 1;
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
	(void)map;
	i = 0;
	hit.x = first.x;
	hit.y = first.y;
	while (i < map.heigth)
	{
		x = (int)(hit.x / TILE_SIZE);
		y = (int)(hit.y / TILE_SIZE);
		if (x >= 0 && y >= 0 && x < map.width && y < map.heigth && map.grid[y][x] == '1')
			return (hit);
		if (angle >= 0 && angle <= M_PI)
			hit.y += TILE_SIZE;
		else
			hit.y -= TILE_SIZE;
		
		hit.x = hit.x + (hit.y - first.y)/ tan(angle);
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
	hit = first;
	while (i < map.width)
	{
		x = (int)(hit.x / TILE_SIZE);
		y = (int)(hit.y / TILE_SIZE);
		if (x >= 0 && x < map.width && y >= 0 && y < map.heigth && map.grid[y][x] == '1')
			return (hit);
		if (angle > M_PI / 2 && angle < 1.5 * M_PI)
			hit.x -= TILE_SIZE;
		else
			hit.x += TILE_SIZE;
		hit.y = hit.y + (hit.x - first.x)* tan(angle);
		i++;
	}
	return (hit);
}

// double distance()


t_coor	ft_compare(t_coor player, t_coor h, t_coor v)
{
	double PH;
	double PV;

	PH = sqrt(pow(h.y - player.y, 2)+ pow(h.x - player.x, 2));
	PV = sqrt(pow(v.y - player.y, 2)+ pow(v.x - player.x, 2));

	if (PV <= PH)
		return (v);
	else
		return (h);
}


void	ft_dda(t_data *data)
{
	t_coor first_h;
	t_coor first_v;


		first_h = first_h_inter(data->player.angle, data->player.coor);
		first_v = first_v_inter(data->player.angle, data->player.coor);
		t_coor hit_h = h_wall_detect(data->map, first_h, data->player.angle);
		t_coor hit_v = v_wall_detect(data->map, first_v, data->player.angle);
		t_coor small_d = ft_compare(data->player.coor, hit_h, hit_v);
		
		dda(data, data->player.coor, small_d);



	// double angle = data->player.angle - 0.523599;
	
	// while (angle < data->player.angle + 0.523599)// castin rays depened of player angle
	// {
	// 	first_h = first_h_inter(angle, data->player.coor);
	// 	first_v = first_v_inter(angle, data->player.coor);
	// 	t_coor hit_h = h_wall_detect(data->map, first_h, angle);
	// 	t_coor hit_v = v_wall_detect(data->map, first_v, angle);
	// 	t_coor small_d = ft_compare(data->player.coor, hit_h, hit_v);
		
	// 	dda(data, data->player.coor, small_d);
	// 	angle += 0.00872665;
	// }

	// printf("%f\n",hit.x);
	












	
	
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
