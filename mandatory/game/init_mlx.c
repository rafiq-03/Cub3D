/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:31:30 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/04 16:44:03 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"


void	init_mlx_imgs(t_data *data)
{
	mlx_texture_t	*texture_img1;
	mlx_texture_t	*texture_img2;
	mlx_texture_t	*texture_img3;
	mlx_texture_t	*texture_img4;

	texture_img1 = mlx_load_png(data->textures.no);
	texture_img2 = mlx_load_png(data->textures.so);
	texture_img3 = mlx_load_png(data->textures.ea);
	texture_img4 = mlx_load_png(data->textures.we);
	if (!texture_img1 || !texture_img2
		|| !texture_img3 || !texture_img4)
	{
		printf("Load_png Error!\n");
		exit(EXIT_FAILURE);
	}
	data->img1 = mlx_texture_to_image(data->mlx, texture_img1);
	data->img2 = mlx_texture_to_image(data->mlx, texture_img2);
	data->img3 = mlx_texture_to_image(data->mlx, texture_img3);
	data->img4 = mlx_texture_to_image(data->mlx, texture_img4);
	if (!data->img1 || !data->img2 || !data->img3 || !data->img4)
	{
		printf("Texture_to_image Error!\n");
		exit(EXIT_FAILURE);
	}
	mlx_delete_texture(texture_img1);
	mlx_delete_texture(texture_img2);
	mlx_delete_texture(texture_img3);
	mlx_delete_texture(texture_img4);
}

void	init_mlx_elements(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!data->mlx)
	{
		ft_strerr("failed to create mlx pointer");
		return ;
	}
	data->ft_3d = mlx_new_image(data->mlx, WIDTH , HEIGHT);
	if (!data->ft_3d)
	{
		ft_strerr("3d vue's image error");
		exit(EXIT_FAILURE);
	}
	mlx_image_to_window(data->mlx, data->ft_3d, 0 , 0);
	init_mlx_imgs(data);
	// must delete textures
}
