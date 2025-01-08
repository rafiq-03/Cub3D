/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:31:17 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/08 16:04:36 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

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

int	get_height(t_list *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (!ft_strlen(tmp->content))
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_max_len(t_list *tmp)
{
	int	max;
	int	len;

	if (tmp)
		max = ft_strlen(tmp->content);
	while (tmp)
	{
		len = ft_strlen(tmp->content);
		if (len > max)
			max = len;
		tmp = tmp->next;
	}
	return (max);
}

void	del(void *content)
{
	free(content);
}

int	check_line(char *line, char *chars)
{
	int	i;

	i = 0;
	while (chars[i])
	{
		if (ft_strchr(line, chars[i]))
			return (1);
		i++;
	}
	return (0);
}
