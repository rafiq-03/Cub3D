/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:31:30 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/04 16:02:16 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"


void	init_mlx_imgs(t_data *data)
{
	data->texture_img1 = mlx_load_png(data->textures.NO);
	data->texture_img2 = mlx_load_png(data->textures.SO);
	data->texture_img3 = mlx_load_png(data->textures.EA);
	data->texture_img4 = mlx_load_png(data->textures.WE);
	if (!data->texture_img1 || !data->texture_img2
		|| !data->texture_img3 || !data->texture_img4)
	{
		printf("Load_png Error!\n");
		exit(EXIT_FAILURE);
	}
	data->img1 = mlx_texture_to_image(data->mlx, data->texture_img1);
	data->img2 = mlx_texture_to_image(data->mlx, data->texture_img2);
	data->img3 = mlx_texture_to_image(data->mlx, data->texture_img3);
	data->img4 = mlx_texture_to_image(data->mlx, data->texture_img4);
	if (!data->img1 || !data->img2 || !data->img3 || !data->img4)
	{
		printf("Texture_to_image Error!\n");
		exit(EXIT_FAILURE);
	}
}

void	init_mlx_elements(t_data *data)
{
    data->rotate_angle = DEGREE;
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!data->mlx)
	{
		ft_strerr("failed to create mlx pointer");
		return ;
	}
	data->ft_3D = mlx_new_image(data->mlx, WIDTH , HEIGHT);
	if (!data->ft_3D)
	{
		ft_strerr("3d vue's image error");
		exit(EXIT_FAILURE);
	}
	mlx_image_to_window(data->mlx, data->ft_3D, 0 , 0);
	init_mlx_imgs(data);
	// must delete textures
}
