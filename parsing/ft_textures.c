/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:36:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/09 17:01:53 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	add_texture(char **texture, char *line, u_int16_t *flag);
void	clean_textures(t_texture *textures);
void	fill_textures(t_data *data);


void	add_texture(char **texture, char *line, u_int16_t *flag)
{

	if (*texture)
	{
		ft_strerr("duplicate texture");
		exit (1);
	}
	*texture = ft_strtrim(line, "\n");
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

void	fill_textures(t_data *data)
{
	t_list *tmp;
	char **split;
	int		words;

	tmp = data->file_content;
	clean_textures(&data->textures);
	while (tmp && data->textures.flag < 4)
	{
		split = ft_split_ws(tmp->content, " \n", &words);//split content of line by spaces and new line to trim it
		if (words == 2)
		{
			if (!ft_strcmp(split[0], "SO"))
				add_texture(&data->textures.SO, split[1], &data->textures.flag);
			if (!ft_strcmp(split[0], "NO"))
				add_texture(&data->textures.NO, split[1], &data->textures.flag);
			if (!ft_strcmp(split[0], "WE"))
				add_texture(&data->textures.WE, split[1], &data->textures.flag);
			if (!ft_strcmp(split[0], "EA"))
				add_texture(&data->textures.EA, split[1], &data->textures.flag);
		}
		free(split);
		tmp = tmp->next;
	}
	if (data->textures.flag != 4)
	{
		ft_strerr("Textures are not valid");
		exit(EXIT_FAILURE);	
	}
}
