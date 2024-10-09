/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_requirements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:06:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/09 16:44:45 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_args(int ac, char *str);
void fill_map(int fd, t_data *data);

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
	line = get_next_line(fd);
	data->file_content = ft_lstnew(line);
	data->file_content->i = i;
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_lstnew(line);
		ft_lstadd_back(&data->file_content, tmp);
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
	fill_textures(data);
	fill_colors(data);
	// while (1){}
	// printf("this is me\n");
	// fill_map(fd, data);

}

void fill_map(int fd, t_data *data)
{
	char	*line;
	char	*tmp_map;
	int		i;

	i = 0;
	tmp_map = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp_map = ft_strjoin(tmp_map, line);
		line = get_next_line(fd);
	}
	data->map=ft_split(tmp_map, '\n');	
}
