/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:25:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/11 17:51:38 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


void	after_map(t_list *tmp);
t_list *skip_header(t_list *tmp, int end);
void	fill_map(t_data *data);
int	check_all_line(char *line, char *chars);

int	check_all_line(char *line, char *chars)
{
	int	i;

	i = 0;

	while (line[i])
	{
		if (!ft_strchr(chars, line[i]))
			return (1);
		i++;
	}
	return (0);
}
t_list *skip_header(t_list *tmp, int end)
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

void	fill_map(t_data *data)
{
	t_list *tmp;
	int		i;

	i = 0;
	tmp = skip_header(data->file_content, data->header_end);
	data->map.map = ft_calloc(ft_lstsize(tmp) + 1 , sizeof(char *));
	while (tmp)
	{
		if (check_all_line(tmp->content, "NSEW10 "))
		{
			ft_strerr("invalid map's element");
			exit(EXIT_FAILURE);
		}
		if (!ft_strlen(tmp->content))// if there is an empty  line check if there is something after it
		{
			after_map(tmp);
			break;
		}		
		data->map.map[i++] = tmp->content;
		tmp = tmp->next;
	}
	if (check_player(data, data->map.map) != 1)
	{
		ft_strerr("more than player in map");
		exit(EXIT_FAILURE);
	}
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

