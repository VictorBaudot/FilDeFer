/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:38:51 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/03 15:28:44 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void join_points(data_t data)
{
	int x;
	int ix;
	int y;
	int iy;
	int color;
	t_square square;

	y = 0;
	while (data.map[y])
	{
		x = 1;
		while (x < data.map[y][0])
		{
			ix = (x - y) * data.tile_width_half;
			iy = ((x + y) * (data.tile_heigth_half / 2)) - data.map[y][x] * data.depth;
			color = 0xFFFFFF;//get_color(data.map[y][x]);
			if (x > 1)
				draw_segment(ix, iy, ((x - 1) - y) * data.tile_width_half, (((x - 1) + y) * (data.tile_heigth_half / 2)) - data.map[y][x - 1] * data.depth, data, color);
			if (y > 0 && x < data.map[y][0] + 1)
				draw_segment(ix, iy, (x - (y - 1)) * data.tile_width_half, ((x + (y - 1)) * (data.tile_heigth_half / 2)) - data.map[y - 1][x] * data.depth, data, color);
			if (x > 2 && y > 0 && x < data.map[y][0])
			{
				square.a.x = ((x - 1) - (y - 1)) * data.tile_width_half;
				square.b.x = (x - (y - 1)) * data.tile_width_half;
				square.c.x = ((x - 1) - y) * data.tile_width_half;
				square.d.x = ix;
				square.a.y = (((x - 1) + (y - 1)) * (data.tile_heigth_half / 2)) - data.map[y - 1][x - 1] * data.depth;
				square.b.y = ((x + (y - 1)) * (data.tile_heigth_half / 2)) - data.map[y - 1][x] * data.depth;
				square.c.y = (((x - 1) + y) * (data.tile_heigth_half / 2)) - data.map[y][x - 1] * data.depth;
				square.d.y = iy;
				fill_square(square);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
}

void print_map_points(data_t data)
{
	int x;
	int ix;
	int iy;
	int y;

	y = 0;
	while (data.map[y])
	{
		x = 1;
		while (x < data.map[y][0])
		{
			ix = (x - y) * data.tile_width_half;
			iy = ((x + y) * (data.tile_heigth_half / 2)) - data.map[y][x] * data.depth;
			data.img.data[(iy + get_center_v(data)) * data.win_width + ix + get_center_h(data)] = 0xFF00FF;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
}
