#include "game.h"

void	draw_player(t_data *data, t_coor coor, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while( i < 4)
	{
		j = 0;
		while (j < 4)
		{
			my_mlx_put_pixel(data, img, (t_coor){coor.x + i - 2, coor.y + j - 2}, get_rgba(96, 86, 120, 255));
			dda(data, coor , (t_coor) {coor.x + cos(data->player.angle) * 10, coor.y + sin(data->player.angle) * 10}, get_rgba(96, 86, 120, 255), data->ft_3D);
			j++;
		}
		i++;
	}
}

void mini_map(t_data *data)
{
	double x;
	double y;

	int i = 0;
	int j = 0;
	y = data->player.coor.y - 5 * TILE_SIZE;
	while (j < MINI_HEIGHT)
	{ 
		x = data->player.coor.x - 10 * TILE_SIZE;
		i = 0;
		while (i < MINI_WIDTH)
		{
			if (x >= 0 && x < (data->map.width * TILE_SIZE) && y >= 0 && y < (data->map.heigth * TILE_SIZE))
			{
				if (data->map.grid[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
					my_mlx_put_pixel(data, data->ft_3D, (t_coor){i , j}, get_rgba(0, 0, 0, 255));
				if (data->map.grid[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '0'
				|| ft_strchr("NSEW", data->map.grid[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)]))
					my_mlx_put_pixel(data, data->ft_3D, (t_coor){i , j}, get_rgba(246, 230, 203, 255));
			}
			x++;
			i++;
		}
		y++;
		j++;
	}
	draw_player(data, (t_coor){10 * TILE_SIZE, 5 * TILE_SIZE}, data->ft_3D);
}
