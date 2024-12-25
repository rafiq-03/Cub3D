/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:34:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/25 20:50:30 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void render_background(t_data *data)
{
    int i = 0;
	int j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				mlx_put_pixel(data->ft_3D, j, i, get_rgba(data->colors.C.r, data->colors.C.g, data->colors.C.b, 255));
			else
				mlx_put_pixel(data->ft_3D, j, i, get_rgba(data->colors.F.r, data->colors.F.g, data->colors.F.b, 255));
			j++;
		}
		i++;
	}
}

void	render_all(t_data *data)
{
    render_background(data);
	projection_3D(data);
}
