/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:38:51 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/16 15:49:56 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_player(t_data *data, t_coor coor)
{
	int	i;
	int	j;

	i = 0;
	while( i < 4)
	{
		j = 0;
		while (j < 4)
		{
			my_mlx_put_pixel(data, data->map.img, (t_coor){coor.x + i - 2, coor.y + j - 2}, get_rgba(96, 86, 120, 255));
			j++;
		}
		i++;
	}
}
