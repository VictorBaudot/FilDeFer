/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:38:51 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/02 15:19:01 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void join_points(data_t data)
{
	int x;
	int ix;
	int y;
	int iy;

	y = 0;
	while (data.map[y])
	{
		x = 1;
		while (x < data.map[y][0])
		{
			ix = (x - y) * TILE_WIDTH_HALF;
			iy = ((x + y) * (TILE_HEIGHT_HALF / 2)) - data.map[y][x] * 6;
			if (x > 1)
				draw_segment(ix, iy, ((x - 1) - y) * TILE_WIDTH_HALF, (((x - 1) + y) * (TILE_HEIGHT_HALF / 2)) - data.map[y][x - 1] * 6, data);
			if (y > 0 && x < data.map[y][0] + 1)
				draw_segment(ix, iy, (x - (y - 1)) * TILE_WIDTH_HALF, ((x + (y - 1)) * (TILE_HEIGHT_HALF / 2)) - data.map[y - 1][x] * 6, data);
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
			ix = (x - y) * TILE_WIDTH_HALF;
			iy = ((x + y) * (TILE_HEIGHT_HALF / 2)) - data.map[y][x] * 6;
			data.img.data[(iy + 100) * WIN_WIDTH + ix + 450] = 0xFF00FF;
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
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			data.img.data[y * WIN_WIDTH + x] = 0x000000;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
}
