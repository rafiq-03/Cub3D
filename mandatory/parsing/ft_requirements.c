/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_requirements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:06:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/25 20:07:34 by rmarzouk         ###   ########.fr       */
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
		tmp = ft_lstnew(ft_strtrim(line, "\n\t"));
		tmp->i = i++;
		ft_lstadd_back(&data->file_content, tmp);
		free(line);
		line = get_next_line(fd);
		// printf("%s\n", tmp->content);
	}
	close(fd);
}

void check_textures_colors(t_data *data)
{
	t_list *tmp;
	char **split;
	char *line;
	int		words;

	tmp = data->file_content;
	clean_textures(&data->textures);
	data->colors.flag = 0;
	while (tmp)
	{
		line = ft_strtrim(tmp->content, " \n\b\t\r");
		if (!ft_strlen(line))// skip empty lines
		{
			tmp = tmp->next;
			continue;
		}
		split = ft_split_ws(line, " ", &words);
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
		else if (!check_all_line(line, "NSWE10 ") && data->textures.flag == 4
			&& data->colors.flag == 3)// it is map
		{
			printf ("%s\n", line);
			tmp = tmp->next;
			continue;
		}
		else
		{
			ft_strerr("ivalid texture or color");
			exit(EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
	
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
	check_textures_colors(data);
	// fill_textures(data);
	// fill_colors(data);
	// fill_map(data);
	printf ("mzyan\n");
	ft_lstclear(&data->file_content, &del);
}

void	print_map(t_data *data)
{
	int i = 0;
	printf("-----------------------------------------------\n");
	while (data->map.grid[i])
	{
		printf("|%s| \n", data->map.grid[i]);
		i++;
	}
	printf("-----------------------------------------------\n");
}
