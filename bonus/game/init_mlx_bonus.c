/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:31:30 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/08 17:12:13 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	init_mlx_imgs(t_data *data)
{
	data->texture1 = mlx_load_png(data->textures.no);
	data->texture2 = mlx_load_png(data->textures.so);
	data->texture3 = mlx_load_png(data->textures.ea);
	data->texture4 = mlx_load_png(data->textures.we);
	if (!data->texture1 || !data->texture2
		|| !data->texture3 || !data->texture4)
	{
		printf("Load_png Error!\n");
		exit(EXIT_FAILURE);
	}
}

void	init_mlx_elements(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!data->mlx)
	{
		ft_strerr("failed to create mlx pointer");
		return ;
	}
	data->ft_3d = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->ft_3d)
	{
		ft_strerr("3d vue's image error");
		exit(EXIT_FAILURE);
	}
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(data->mlx, &data->mouse_p.x, &data->mouse_p.y);
	data->tmp_mouse = data->mouse_p.x;
	mlx_image_to_window(data->mlx, data->ft_3d, 0, 0);
	init_mlx_imgs(data);
}
