/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:34:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/13 15:37:33 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int get_rgba(int r, int g, int b, int a);
void	draw_player(t_data *data, t_coor coor);

void	dda(t_data *data, t_coor a, t_coor b)
{
	int step;
	double dx;
	double dy;

	double xinc;
	double yinc;

	a.x *= BOX;
	a.y *= BOX;
	b.x *= BOX;
	b.y *= BOX;
	
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
		mlx_put_pixel(data->map.img, a.x, a.y, get_rgba(255, 110, 0, 255));
		a.x += xinc;
		a.y += yinc;
		i++;
	}
}


void	ft_dda(t_data *data)
{
	t_coor point;

	point.x = data->player.coor.x - 1;
	point.y = data->player.coor.y + 2;
	// printf("[%f, %f]\n", point.x, point.y);
	// draw_player(data, point);
	dda(data, data->player.coor, data->player.pov);
}
