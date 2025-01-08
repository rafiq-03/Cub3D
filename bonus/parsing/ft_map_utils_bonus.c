/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:51:30 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/08 16:05:25 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	set_angle(t_player *player, char c)
{
	if (c == 'N')
		player->angle = 270 * M_PI / 180;
	if (c == 'S')
		player->angle = 90 * M_PI / 180;
	if (c == 'E')
		player->angle = 0.0;
	if (c == 'W')
		player->angle = M_PI;
}

int	check_player(t_data *data, char **map)
{
	int	x;
	int	y;
	int	nb;

	nb = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSWE", map[y][x]))
			{
				data->player.coor.x = x * TILE_SIZE + TILE_SIZE / 2;
				data->player.coor.y = y * TILE_SIZE + TILE_SIZE / 2;
				set_angle(&data->player, map[y][x]);
				nb++;
			}
			x++;
		}
		y++;
	}
	return (nb);
}

void	check_edges(char **map, int height, int width)
{
	int	i;

	i = 0;
	if (check_line(map[0], "NSWE0") || check_line(map[height - 1], "NSWE0"))
	{
		ft_strerr("0 in edges");
		exit(EXIT_FAILURE);
	}
	while (i < height)
	{
		if (ft_strchr("NSWE0", map[i][0])
		|| ft_strchr("NSWE0", map[i][width - 1]))
		{
			ft_strerr("0 in edges");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_around(char **map, int x, int y)
{
	if (map[y - 1][x] == ' ' || map[y][x + 1] == ' ' 
	|| map[y][x - 1] == ' ' || map[y + 1][x] == ' ')
	{
		ft_strerr("map is not surrounded by walls");
		exit(EXIT_FAILURE);
	}
}

void	check_all_map(char **map, int hight, int width)
{
	int	x;
	int	y;

	y = 1;
	while (y < hight - 1)
	{
		x = 1;
		while (x < width - 1)
		{
			if (map[y][x] == '0' || ft_strchr("NSWE", map[y][x]))
				check_around(map, x, y);
			x++;
		}
		y++;
	}
}
