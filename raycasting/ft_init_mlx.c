/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:31:30 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/13 13:33:04 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_mlx_elements(t_data *data)
{
	/*
		player		img
		map			img
		background	img
		mlx pointer;
	*/
	data->mlx = mlx_init(data->map.width * BOXE, data->map.heigth * BOXE, "CUB3D", false);// 5 just for testing
	if (!data->mlx)
	{
		ft_strerr("failed to create mlx pointer");
		return ;
	}
	data->ft_3D = mlx_new_image(data->mlx, data->map.width * BOXE , data->map.heigth * BOXE);
	if (!data->ft_3D)
	{
		ft_strerr("3d vue's image error");
		exit(EXIT_FAILURE);
	}
	data->map.img = mlx_new_image(data->mlx, data->map.width * BOX, data->map.width * BOX);
	if (!data->map.img)
	{
		ft_strerr("map's img error");
		exit(EXIT_FAILURE);
	}
	mlx_image_to_window(data->mlx, data->map.img, 0 , 0);
}
