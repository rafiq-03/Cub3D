/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:54:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/07 15:01:35 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ll(void)
{
	//system("leaks -q cub3D | grep \'leaks for\' | awk \'{print $3 ,$4}\'");
	system("leaks -q cub3D");
}

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
}

int	main(int ac, char **av)
{
	t_data	data;

	/*atexit(ll);*/
	check_requirements(ac, av, &data);
	init_mlx_elements(&data);
	mlx_loop_hook(data.mlx, ft_loop, &data);
	mlx_loop(data.mlx);
	clean_all(&data);
	/*must delete textures*/
}
