/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:51:30 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/11 16:06:16 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_player(t_data *data, char **map)
{
	int	x;
	int	y;
	int nb;
	
	nb = 0;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (ft_strchr("NSWE", map[x][y]))
			{
				data->map.player.x = x;
				data->map.player.y = y;
				data->map.derection = map[x][y];
				nb++;
			}
			y++;
		}
		x++;		
	}
	return (nb);
}
