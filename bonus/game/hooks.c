/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:06:49 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/25 11:35:56 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	collision_detected(t_map map, t_coor p_coor)
{
	t_coor coor = p_coor;
	coor.y = p_coor.y - 4;
	while (coor.y < p_coor.y + 4)
	{
		coor.x = p_coor.x - 4;
		while (coor.x < p_coor.x + 4)
		{
			if (map.grid[(int)(coor.y / TILE_SIZE)] 
			&& map.grid[(int)(coor.y / TILE_SIZE)][(int)(coor.x / TILE_SIZE)] 
			&& map.grid[(int)(coor.y / TILE_SIZE)][(int)(coor.x / TILE_SIZE)] == '1')
			return (1);
			coor.x++;
		}
		coor.y++;	
	}
	return (0);
}

void	key_hooks(t_data *data)
{
	t_coor next;

	next = data->player.coor;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->player.angle = ft_normalizer(data->player.angle + data->rotate_angle);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->player.angle = ft_normalizer(data->player.angle - data->rotate_angle);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) || mlx_is_key_down(data->mlx, MLX_KEY_UP))
	{
		next.x = data->player.coor.x + cos(data->player.angle) * SPEED ;
		next.y = data->player.coor.y + sin(data->player.angle) * SPEED ;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) || mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
	{
		next.x = data->player.coor.x - cos(data->player.angle) * SPEED ;
		next.y = data->player.coor.y - sin(data->player.angle) * SPEED ;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		next.x = data->player.coor.x + cos(data->player.angle - DEGREE_90) * SPEED ;
		next.y = data->player.coor.y +  sin(data->player.angle - DEGREE_90) * SPEED ;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		next.x = data->player.coor.x + cos(data->player.angle + DEGREE_90) * SPEED ;
		next.y = data->player.coor.y + sin(data->player.angle + DEGREE_90) * SPEED ;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	if (!collision_detected(data->map, next))
		data->player.coor = next;
}

