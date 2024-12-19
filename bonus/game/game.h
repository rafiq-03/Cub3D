/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:31:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/23 16:01:29 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H


#include "../cub3D.h"

void	init_mlx_elements(t_data *data);
void	my_mlx_put_pixel(t_data *data, mlx_image_t *img, t_coor coor, u_int32_t color);
int		get_rgba(int r, int g, int b, int a);
void	draw_tile(t_data *data, int	x, int y, char c, mlx_image_t *img);
void	draw_player(t_data *data, t_coor coor, mlx_image_t *img);

void	keyhooks(mlx_key_data_t	keydata, void *dataa);
double	ft_normalizer(double angle);
void	projection_3D(t_data *data);
void	dda(t_data *data, t_coor a, t_coor b, int color, mlx_image_t *img);

int gett_rgba(uint8_t *color);

void	render_all(t_data *data);

t_coor	first_h_inter(double angle, t_coor player);
t_coor	first_v_inter(double angle, t_coor player);
t_coor h_wall_detect(t_map map, t_coor first, double angle);
t_coor v_wall_detect(t_map map, t_coor first, double angle);
t_coor	ft_compare(t_coor player, t_coor h, t_coor v, t_ray *ray);

void	draw_columns(t_data *data, t_ray *ray, double angle);
void render_background(t_data *data);

// testing
void mini_map(t_data *data);

#endif
