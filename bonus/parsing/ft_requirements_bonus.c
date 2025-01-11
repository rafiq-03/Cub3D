/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_requirements_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:06:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/11 17:20:06 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	check_args(int ac, char *str)
{
	if (ac != 2)
	{
		ft_strerr("Prototype : ./cub3D [ path_to_map.cub ]");
		exit (1);
	}
	if (ft_strcmp(".cub", str + ft_strlen(str) - 4))
	{
		ft_strerr("extension must be [ ___.cub ]");
		exit (1);
	}
}

void	fill_file_content(t_data *data, int fd)
{
	char	*line;
	int		i;
	t_list	*tmp;

	i = 0;
	data->file_content = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_lstnew(ft_strtrim(line, "\n"));
		tmp->i = i++;
		ft_lstadd_back(&data->file_content, tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	check_color_teture(t_data *data, char *line)
{
	char	**split;
	int		words;

	split = ft_split_ws(line, " \t", &words);
	if (words == 2)
	{
		if (texture_color(split[0]) == 1)
			fill_textures(data, split);
		else if (texture_color(split[0]) == 2)
			fill_colors(data, line);
		else
		{
			ft_strerr("invalid texture or color");
			exit (EXIT_FAILURE);
		}
	}
	else if (words > 2 && texture_color(split[0]) == 2)
		fill_colors(data, line);
	else
	{
		ft_strerr("ivalid texture or color");
		exit(EXIT_FAILURE);
	}
	ft_free (split);
}

void	fill_textures_colors(t_data *data, t_list *tmp)
{
	char	*line;

	while (tmp)
	{
		if (data->textures.flag == 4 && data->colors.flag == 3)
		{
			data->header_end = tmp->i;
			break ;
		}
		line = ft_strtrim(tmp->content, " \n\b\t\r");
		if (!ft_strlen(line))
		{
			tmp = tmp->next;
			free (line);
			continue ;
		}
		check_color_teture(data, line);
		tmp = tmp->next;
		free (line);
	}
}

void	check_requirements(int ac, char **av, t_data *data)
{
	int		fd;
	t_list	*tmp;

	check_args(ac, av[1]);
	clean_textures(&data->textures);
	data->colors.flag = 0;
	fd = open (av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("error\n => ");
		exit (EXIT_FAILURE);
	}
	fill_file_content(data, fd);
	if (!ft_lstsize(data->file_content))
	{
		ft_strerr("empty file");
		exit(EXIT_FAILURE);
	}
	tmp = data->file_content;
	fill_textures_colors(data, tmp);
	fill_map(data);
	ft_lstclear(&data->file_content, &del);
}
