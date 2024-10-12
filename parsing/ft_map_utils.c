/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:51:30 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/12 15:31:46 by rmarzouk         ###   ########.fr       */
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
				data->player.pos.x = x;
				data->player.pos.y = y;
				data->player.direction = map[x][y];
				nb++;
			}
			y++;
		}
		x++;		
	}
	return (nb);
}
int	check_line(char *line, char *chars)
{
	int	i = 0;
	while (chars[i])
	{
		if (ft_strchr(line, chars[i]))
			return (1);
		i++;
	}
	return (0);
}

void	check_edges(char **map, int height, int width)
{
	int	i;

	i = 0;
	// if (check_line(map[0], '0') || ft_strchr(map[hight - 1], '0'))
	if (check_line(map[0], "NSWE0") || check_line(map[height - 1], "NSWE0"))
	{
		ft_strerr("0 in edges");
		exit(EXIT_FAILURE);
	}
	// printf("hereeee\n\n\n\n\n");
	while (i < height)
	{
		// if (map[i][0] == '0' || map[i][width - 1] == '0')
		if (ft_strchr("NSWE0", map[i][0]) || ft_strchr("NSWE0", map[i][width - 1]))
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
