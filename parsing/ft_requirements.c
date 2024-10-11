/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_requirements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:06:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/11 17:34:18 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	del(void *content)
{
	free(content);
}
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
	char *line;
	int		i;
	t_list	*tmp;

	i = 0;
	data->file_content = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_lstnew(ft_strtrim(line, "\n"));
		tmp->i = i++;
		// printf("%d \n", data->file_content->i);
		ft_lstadd_back(&data->file_content, tmp);
		free(line);
		line = get_next_line(fd);
	}
	// free this fucking data we don't want leaks
	close(fd);
}

void	check_requirements(int ac, char **av, t_data *data)
{
	int fd;

	check_args(ac, av[1]);
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
	fill_textures(data);
	fill_colors(data);
	fill_map(data);
	// char **str = data->map.map;
	// while (*str)
	// 	printf("%s\n", *str++);
	ft_lstclear(&data->file_content, &del);
}
