/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:54:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/05 11:47:01 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(void)
{
	mlx_t *mlx;
	mlx = mlx_init(1000, 1000, "Cube3D", false);
	mlx_loop(mlx);
	printf("hello world\n");
}
