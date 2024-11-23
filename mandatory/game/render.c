/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:34:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/23 16:43:57 by rmarzouk         ###   ########.fr       */
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
				mlx_put_pixel(data->ft_3D, j, i, get_rgba(62, 43, 43, 240));
			else
				mlx_put_pixel(data->ft_3D, j, i, get_rgba(123, 62, 11, 169));
			j++;
		}
		i++;
	}
}

void	render_all(t_data *data)
{
    render_background(data);
	projection_3D(data);
	mini_map(data);
	// rander_walls();
}
