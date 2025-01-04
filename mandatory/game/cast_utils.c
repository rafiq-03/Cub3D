/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:58:20 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/04 13:44:19 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_coor	first_h_inter(double angle, t_coor player)
{
	t_coor	first_h;

	angle = ft_normalizer(angle);
	if (angle >= 0 && angle <= M_PI) // down
		first_h.y = floor(player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	else if (angle > M_PI && angle < 2 * M_PI) // up
		first_h.y = floor(player.y / TILE_SIZE) * TILE_SIZE - 0.00000001;
	first_h.x = (first_h.y - player.y) / tan(angle) + player.x;
	return (first_h);
}

t_coor	first_v_inter(double angle, t_coor player)
{
	t_coor	first_v;

	if (angle >= M_PI / 2 && angle <= 1.5 * M_PI) //left
		first_v.x = (int)(player.x / TILE_SIZE) *TILE_SIZE - 0.00000001;
	else if (angle >= 1.5 * M_PI || angle <= M_PI / 2) // right
		first_v.x = (int)(player.x / TILE_SIZE) *TILE_SIZE + TILE_SIZE;
	first_v.y = player.y + tan(angle) * (first_v.x - player.x);
	return (first_v);
}

void	ft_horizontal(t_coor *hit, double angle)
{
	if (angle >= 0 && angle < M_PI) // down
	{
		hit->y += TILE_SIZE;
		hit->x += (TILE_SIZE) / tan(angle);
	}
	else // up
	{
		hit->y -= TILE_SIZE;
		hit->x -= TILE_SIZE / tan(angle);
	}
}

void	ft_vertical(t_coor *hit, double angle)
{
	if (angle > M_PI / 2 && angle < 1.5 * M_PI) // left
	{
		hit->x -= TILE_SIZE;
		hit->y -= TILE_SIZE * tan(angle);
	}
	else // right
	{
		hit->x += TILE_SIZE;
		hit->y += TILE_SIZE * tan(angle);
	}
}

t_coor	ft_compare(t_coor player, t_coor h, t_coor v, t_ray *ray)
{
	double	ph;
	double	pv;

	ph = sqrt(pow(h.y - player.y, 2) + pow(h.x - player.x, 2));
	pv = sqrt(pow(v.y - player.y, 2) + pow(v.x - player.x, 2));
	if (pv <= ph)
	{
		ray->distance = pv;
		ray->flag = 'v';
		return (v);
	}
	else
	{
		ray->distance = ph;
		ray->flag = 'h';
		return (h);
	}
}
