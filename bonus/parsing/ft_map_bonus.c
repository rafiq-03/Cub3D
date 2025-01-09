/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:25:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/09 13:49:41 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

t_list	*skip_header(t_list *tmp, int end)
{
	while (tmp)
	{
		if (tmp->i == end)
		{
			while (tmp && !ft_strlen(tmp->content))
				tmp = tmp->next;
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	_loop(t_data *data, t_list *tmp, int i)
{
	while (tmp)
	{
		if (check_all_line(tmp->content, "NSEW10 "))
		{
			ft_strerr("invalid map's element");
			exit(EXIT_FAILURE);
		}
		if (!ft_strlen(tmp->content)) 
		{
			after_map(tmp);
			break ;
		}
		data->map.grid[i] = ft_calloc(data->map.width + 1, sizeof(char));
		if (!data->map.grid[i])
			return ;
		ft_memset(data->map.grid[i], ' ', data->map.width);
		ft_memcpy(data->map.grid[i++], tmp->content, ft_strlen(tmp->content));
		tmp = tmp->next;
	}
}

void	check_limits(t_data *data)
{
	if (data->map.heigth > 1000 || data->map.width > 1000)
	{
		ft_strerr("map is too big");
		exit(EXIT_FAILURE);
	}
}

void	fill_map(t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = skip_header(data->file_content, data->header_end);
	data->map.heigth = get_height(tmp);
	if (!data->map.heigth)
	{
		ft_strerr("ther is not map in this file or map in the middle");
		exit(EXIT_FAILURE);
	}
	data->map.width = ft_max_len(tmp);
	check_limits(data);
	data->map.grid = ft_calloc(data->map.heigth + 1, sizeof(char *));
	if (!data->map.grid)
		return ;
	_loop(data, tmp, i);
	if (check_player(data, data->map.grid) != 1)
	{
		ft_strerr("more or less than player in map");
		exit(EXIT_FAILURE);
	}
	check_edges(data->map.grid, data->map.heigth, data->map.width);
	check_all_map(data->map.grid, data->map.heigth, data->map.width);
}

void	after_map(t_list *tmp)
{
	while (tmp)
	{
		if (ft_strlen(tmp->content))
		{
			ft_strerr("something after map's Grid");
			exit(EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
}
