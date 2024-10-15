/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/15 10:17:40 by rmarzouk         ###   ########.fr       */
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

void	ft_dda(t_data *data)
{
	

	// t_coor A , B;
	// // t_coor h_hit;
	
	
	// // if (data->player.angle >= 0 && data->player.angle < M_PI)
	// // 	A.y = (int)(data->player.coor.y / BOX) * BOX + BOX;
	// // if (data->player.angle >= 0 && data->player.angle < PI)
	// if (data->player.angle >= M_PI && data->player.angle < 2 * PI)
	// 	A.y = (int)(data->player.coor.y / BOX) * BOX - 1;
	// A.x = (A.y - data->player.coor.y) / tan(data->player.angle) + data->player.coor.x;
	
	// B.y = A.y - BOX;
	// // printf("By = %f\n", B.y);
	// B.x = A.x - BOX / tan(data->player.angle);
	// B.x = A.x;
	// printf("angle = %f\n", data->player.angle);
	// printf("Bx = %f\n", B.x);
	// h_hit.x = data->player.coor.x;
	// h_hit.y = data->player.coor.y;
	
	// printf("x = %d, y = %d\n", (int)(h_hit.x / BOX), (int)(h_hit.y / BOX));
	// 	if (data->player.angle >= M_PI && data->player.angle < 2 * M_PI)
	// 		h_hit.y = (int)(data->player.coor.y / BOX) * BOX - 1;
	// 	h_hit.x = (h_hit.y - data->player.coor.y) / tan(data->player.angle) + data->player.coor.x;
	
	// while (data->map.grid[(int)(h_hit.y / BOX)][(int)(h_hit.x / BOX)] != '1')
	// {
	// 	h_hit.y = h_hit.y - BOX;
	// 	h_hit.x = h_hit.x - BOX / tan(data->player.angle);
	// }

	
	
	// dda(data, data->player.coor, A);
	// dda(data, data->player.coor, B);
	// dda(data, A, B);
	// printf("ay = %.2f, ax = %.2f\n", A.y, A.x);

	// A.x = 
	
	
	

	
	// dda(data, data->player.coor, (t_coor){data->player.coor.x + cos(data->player.angle) * 150,
	// 	data->player.coor.y + sin(data->player.angle) * 150});

	
		
	double angle = data->player.angle - 0.785398;
	
	while (angle < data->player.angle + 0.785398)// castin rays depened of player angle
	{
		dda(data, data->player.coor, (t_coor){data->player.coor.x + cos(angle) * 100,
		data->player.coor.y + sin(angle) * 100});
		angle += 0.00872665;
	}
}
