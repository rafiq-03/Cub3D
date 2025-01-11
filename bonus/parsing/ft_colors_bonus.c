/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:16:33 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/11 17:18:00 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
	{
		i++;
		if (!str[i])
			return (0);
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_color(char *str)
{
	char	**tmp;
	int		words;
	int		nb;

	words = 0;
	tmp = ft_split_ws(str, " \t\b\r", &words);
	if (words == 1 && is_number(tmp[0]))
	{
		nb = ft_atoi(tmp[0]);
		if (nb >= 0 && nb <= 255)
		{
			ft_free(tmp);
			return (nb);
		}
	}
	ft_free(tmp);
	return (-1);
}

void	add_color(t_data *data, char **r, char **gb)
{
	if (check_color(r[1]) != -1
		&& check_color(gb[1]) != -1 && check_color(gb[2]) != -1)
	{
		if (!ft_strcmp(r[0], "F"))
		{
			data->colors.f.r = ft_atoi(r[1]);
			data->colors.f.g = ft_atoi(gb[1]);
			data->colors.f.b = ft_atoi(gb[2]);
			data->colors.flag += 2;
		}
		else if (!ft_strcmp(r[0], "C"))
		{
			data->colors.c.r = ft_atoi(r[1]);
			data->colors.c.g = ft_atoi(gb[1]);
			data->colors.c.b = ft_atoi(gb[2]);
			data->colors.flag++;
		}
	}
}

int	n_chars(char *str, char c)
{
	int	num;

	num = 0;
	if (!str)
		return (num);
	while (*str)
	{
		if (*str == c)
			num++;
		str++;
	}
	return (num);
}

void	fill_colors(t_data *data, char *line)
{
	char	**split_1;
	char	**split_2;
	int		words;

	if (n_chars(line, ',') != 2)
	{
		ft_strerr("Invalid color line");
		exit(EXIT_FAILURE);
	}
	split_1 = ft_split_ws(line, ",\n", &words);
	if (words == 3)
	{
		split_2 = ft_split_ws(split_1[0], "\t ", &words);
		if (words == 2)
			add_color(data, split_2, split_1);
		ft_free(split_2);
	}
	ft_free(split_1);
}
