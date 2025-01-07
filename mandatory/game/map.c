/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:26:27 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/07 15:19:10 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	draw_player(t_data *data, t_coor coor, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			my_mlx_put_pixel(data, img, (t_coor){coor.x + i - 2,
				coor.y + j - 2}, get_rgba(96, 86, 120, 255));
			j++;
		}
		i++;
	}
}
