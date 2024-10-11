/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:51:30 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/11 19:04:33 by rmarzouk         ###   ########.fr       */
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
void	check_edges(char **map, int hight, int width)
{
	int	i;

	i = 0;
	if (ft_strchr(map[0], '0') || ft_strchr(map[hight - 1], '0'))
	{
		ft_strerr("0 in edges");
		exit(EXIT_FAILURE);
	}
	while (i < hight)
	{
		if (map[i][0] == '0' || map[i][width - 1] == '0')
		{
			ft_strerr("0 in edges");
			exit(EXIT_FAILURE);
		}
		i++;	
	}
}
void	check_around(char **map, int x, int y)
{
	if (map[x - 1][y] == ' ' || map[x - 1][y] == ' ' || map[x - 1][y + 1] == ' ' || map[x][y - 1] == ' ' || map[x][y + 1] == ' ' || map[x + 1][y - 1] == ' ' || map[x + 1][y] == ' ' || map[x + 1][y + 1] == ' ')
	{
		ft_strerr("map is not surrounded by walls");
		exit(EXIT_FAILURE);
	}
}

void	check_all_map(char **map, int hight, int width)
{
	int	x;
	int	y;

	x = 1;
	while (x < hight - 1)
	{
		y = 1;
		while (y < width - 1)
		{
			if (map[x][y] == '0' || ft_strchr("NSWE", map[x][y]))
				check_around(map, x, y);
			y++;
		}
		x++;
	}
	
}
