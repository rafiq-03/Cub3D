/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:54:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/23 16:44:09 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
void	init_mlx_elements(t_data *data);

void	ll(void)
{
	// system("leaks -q cub3D | grep \'leaks for\' | awk \'{print $3 ,$4}\'");
	system("leaks -q cub3D");
}

void	ft_loop(void *dataa)
{
	t_data *data;
	data = (t_data *) dataa;
	key_hooks(dataa);
	cast_rays(data);
	render_all(data);
}

void	clean_all(t_data *data)
{
	ft_free(data->map.grid);
	free(data->textures.NO);
	free(data->textures.SO);
	free(data->textures.WE);
	free(data->textures.EA);
	// system("leaks cub3D");
}

int main(int ac, char **av)
{
	t_data data;

	// atexit(ll);
	check_requirements(ac, av,&data);
	init_mlx_elements(&data);
	mlx_loop_hook(data.mlx, ft_loop, &data);
	mlx_loop(data.mlx);
	clean_all(&data);
}
