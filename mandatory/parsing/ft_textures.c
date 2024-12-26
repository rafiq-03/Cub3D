/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:36:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/26 15:24:59 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_texture(char **texture, char *line, u_int16_t *flag)
{
	if (*texture)
	{
		ft_strerr("duplicate texture");
		exit (EXIT_FAILURE);
	}
	*texture = ft_strdup(line);
	(*flag)++;
}

void	clean_textures(t_texture *textures)
{
	textures->EA = NULL;
	textures->WE = NULL;
	textures->SO = NULL;
	textures->NO = NULL;
	textures->flag = 0;
}

int	texture_color(char *s)
{
	if (!ft_strcmp(s, "SO") || !ft_strcmp(s, "NO")
		|| !ft_strcmp(s, "EA") || !ft_strcmp(s, "WE"))
		return (1);
	else if (!ft_strcmp(s, "C") || !ft_strcmp(s, "F"))
		return (2);
	return (0);
}

void	fill_textures(t_data *data, char **split)
{
	if (!ft_strcmp(split[0], "SO"))
		add_texture(&data->textures.SO, split[1], &data->textures.flag);
	else if (!ft_strcmp(split[0], "NO"))
		add_texture(&data->textures.NO, split[1], &data->textures.flag);
	else if (!ft_strcmp(split[0], "WE"))
		add_texture(&data->textures.WE, split[1], &data->textures.flag);
	else if (!ft_strcmp(split[0], "EA"))
		add_texture(&data->textures.EA, split[1], &data->textures.flag);
}
