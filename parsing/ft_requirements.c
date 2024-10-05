/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_requirements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:06:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/05 16:26:55 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int check_requirements(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		printf("invalid arguments\n");
		return (1);
	}
	if (ft_strncmp(".cub", av[1] + ft_strlen(av[1]) - 4, 4))
	{
		printf("extension must be \' ___.cub \'\n");
		return (1);
	}
	fd = open (av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("failed to open the file\n");
		return (1);
	}
	
	return (0);
	
}
