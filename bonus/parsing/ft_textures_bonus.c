/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:36:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/11 18:41:06 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	add_texture(char **texture, char *line, u_int16_t *flag)
{
	char	*tmp;

	tmp = ft_strtrim(line, "\t ");
	if (*texture)
	{
		ft_strerr("duplicate texture");
		free(tmp);
		exit (EXIT_FAILURE);
	}
	*texture = ft_strdup(tmp);
	free(tmp);
	(*flag)++;
}

void	clean_textures(t_texture *textures)
{
	textures->ea = NULL;
	textures->we = NULL;
	textures->so = NULL;
	textures->no = NULL;
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

void	fill_textures(t_data *data, char **split, char *line)
{
	if (!ft_strcmp(split[0], "SO"))
		add_texture(&data->textures.so, line + 2, &data->textures.flag);
	else if (!ft_strcmp(split[0], "NO"))
		add_texture(&data->textures.no, line + 2, &data->textures.flag);
	else if (!ft_strcmp(split[0], "WE"))
		add_texture(&data->textures.we, line + 2, &data->textures.flag);
	else if (!ft_strcmp(split[0], "EA"))
		add_texture(&data->textures.ea, line + 2, &data->textures.flag);
}
