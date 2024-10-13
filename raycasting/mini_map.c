/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:55:22 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/13 18:08:30 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_dda(t_data *data);

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_box(t_data *data, int	x, int y, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < BOX)
	{
		j = 0;
		while (j < BOX)
		{
			if (c == '1')
				mlx_put_pixel(data->map.img, x + i, y + j , get_rgba(0, 0, 0, 255));
			else if (c == '0' || ft_strchr("NSEW", c))
				mlx_put_pixel(data->map.img, x + i, y + j , get_rgba(246, 241, 241, 255));
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data, t_coor coor)
{
	int	i;
	int	j;

	i = 0;
	while( i < 3)
	{
		j = 0;
		while (j < 3)
		{
			mlx_put_pixel(data->map.img, (coor.x * BOX) + i, (coor.y * BOX) + j, get_rgba(231, 212, 181, 255));
			j++;
		}
		i++;
	}
	// if (data->player.pov.x * BOX > 0 && data->player.pov.y * BOX > 0)
	// 	mlx_put_pixel(data->map.img, data->player.pov.x * BOX, data->player.pov.y * BOX, get_rgba(255, 0, 0, 255));
}
void	draw_line(t_data *data)
{
	int	i;

	i = 0;
	while( i < 100)
	{
		mlx_put_pixel(data->map.img, (data->player.coor.x * BOX) + i, (data->player.coor.y * BOX), get_rgba(100, 212, 181, 255));
		i++;
	}
}

t_coor rotate(t_player player, double degree)
{
	t_coor new;
	t_coor old;

	old.x = player.pov.x - player.coor.x;
	old.y = player.pov.y - player.coor.y;
	new.x = player.coor.x + old.x * cos(degree) - old.y * sin(degree);
	new.y = player.coor.y + old.x * sin(degree) + old.y * cos(degree);
	return (new);
}

void	keyhooks(mlx_key_data_t	keydata, void *dataa)
{
	t_data *data;

	data = (t_data *)dataa;
	(void) keydata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->player.coor.x += 0.1;
		data->player.pov.x += 0.1;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		data->player.coor.x -= 0.1;
		data->player.pov.x -= 0.1;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->player.coor.y += 0.1;
		data->player.pov.y += 0.1;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{

		data->player.coor.y -= 0.1;
		data->player.pov.y -= 0.1;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->player.pov = rotate(data->player, RADIAN);
		// printf("pov x = %f, y = %f\n", data->player.pov.x, data->player.pov.y);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{

		data->player.pov = rotate(data->player, -RADIAN);
		// printf("pov x = %f, y = %f\n", data->player.pov.x, data->player.pov.y);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	mini_map(data);
}

void	move_player(t_data *data)
{
	mlx_key_hook(data->mlx, keyhooks, data);
}

void	ft_loop(void *dataa)
{
	t_data *data;

	data = (t_data *) dataa;
	mini_map(data);
	move_player(data);
}

void	mini_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			draw_box(data, x * BOX, y * BOX, data->map.grid[y][x]);
			x++;
		}
		y++;	
	}
	draw_player(data, data->player.coor);
	ft_dda(data);
	// draw_player(data, data->player.pov);
}
