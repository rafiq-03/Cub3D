/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:54:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/11 18:04:19 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ll(void)
{
	system("leaks -q cub3D | grep \'leaks for\' | awk \'{print $3 ,$4}\'");
}

int main(int ac, char **av)
{
	t_data data;

	// atexit(ll);
	check_requirements(ac, av,&data);
	
}
