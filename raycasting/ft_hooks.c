/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:06:49 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/15 10:24:49 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	keyhooks(mlx_key_data_t	keydata, void *dataa)
{
	t_data *data;

	data = (t_data *)dataa;
	(void) keydata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->player.angle = ft_normalizer(data->player.angle + DEGREE);
		printf("angle = %f\n", data->player.angle);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->player.angle = ft_normalizer(data->player.angle - DEGREE);
		printf("angle = %f\n", data->player.angle);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		data->player.coor.x += cos(data->player.angle) * SPEED ;
		data->player.coor.y += sin(data->player.angle) * SPEED ;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->player.coor.x -= cos(data->player.angle) * SPEED ;
		data->player.coor.y -= sin(data->player.angle) * SPEED ;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->player.coor.x += cos(data->player.angle - 1.5708) * SPEED ;
		data->player.coor.y += sin(data->player.angle - 1.5708) * SPEED ;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		data->player.coor.x += cos(data->player.angle + 1.5708) * SPEED ;
		data->player.coor.y += sin(data->player.angle + 1.5708) * SPEED ;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	mini_map(data);
}
// printf("x = %f, y = %f\n", data->player.coor.x, data->player.coor.y);

void	ft_loop(void *dataa)
{
	t_data *data;

	data = (t_data *) dataa;
	mini_map(data);
	mlx_key_hook(data->mlx, keyhooks, data);
}
