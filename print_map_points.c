/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:38:51 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/02 16:27:45 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_color(int alt)
{
	if (alt == 0)
		return (0x29C815);
	else if (alt > 0)
		return (/*0x6A4706*/0x29C815);
	else
		return (0x0036FE);
}

void join_points(data_t data)
{
	int x;
	int ix;
	int y;
	int iy;
	int color;

	y = 0;
	while (data.map[y])
	{
		x = 1;
		while (x < data.map[y][0])
		{
			ix = (x - y) * data.tile_width_half;
			iy = ((x + y) * (data.tile_heigth_half / 2)) - data.map[y][x] * 6;
			color = get_color(data.map[y][x]);
			if (x > 1)
				draw_segment(ix, iy, ((x - 1) - y) * data.tile_width_half, (((x - 1) + y) * (data.tile_heigth_half / 2)) - data.map[y][x - 1] * 6, data, color);
			if (y > 0 && x < data.map[y][0] + 1)
				draw_segment(ix, iy, (x - (y - 1)) * data.tile_width_half, ((x + (y - 1)) * (data.tile_heigth_half / 2)) - data.map[y - 1][x] * 6, data, color);
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
			//printf("%d ", param->map[y][x]);
			ix = (x - y) * data.tile_width_half;
			iy = ((x + y) * (data.tile_heigth_half / 2)) - data.map[y][x] * 6;
			data.img.data[(iy + 100) * data.win_width + ix + (data.nb_lines * data.tile_width_half)] = 0xFF00FF;
			x++;
		}
		//printf("\n");
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
}

void all_black(data_t data)
{
	int x;
	int y;

	y = 0;
	while (y < data.win_height)
	{
		x = 0;
		while (x < data.win_width)
		{
			data.img.data[y * data.win_width + x] = 0x000000;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
}
