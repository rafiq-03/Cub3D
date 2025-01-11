/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:54:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/11 17:24:13 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_loop(void *dataa)
{
	t_data	*data;

	data = (t_data *) dataa;
	key_hooks(dataa);
	cast_render(data);
}

void	clean_all(t_data *data)
{
	ft_free(data->map.grid);
	free(data->textures.no);
	free(data->textures.so);
	free(data->textures.we);
	free(data->textures.ea);
	mlx_delete_texture(data->texture1);
	mlx_delete_texture(data->texture2);
	mlx_delete_texture(data->texture3);
	mlx_delete_texture(data->texture4);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_requirements(ac, av, &data);
	init_mlx_elements(&data);
	mlx_loop_hook(data.mlx, ft_loop, &data);
	mlx_loop(data.mlx);
	clean_all(&data);
}
