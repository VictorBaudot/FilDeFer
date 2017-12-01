/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:38:51 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/01 17:57:15 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void join_points(data_t data)
{
	int x;
	int ix;
	int iy;
	int movex;
	int movey;
	int y;

	y = 0;
	movey = 50;
	while (data.map[y])
	{
		x = 1;
		movex = 50;
		while (x < data.map[y][0])
		{
			ix = (x - y) * TILE_WIDTH_HALF;
			iy = (x + y) * TILE_HEIGHT_HALF;/*
			if (x + 1 < data.map[y][0] && data.map[y][x] == 0 && data.map[y][x + 1] == 0)
				draw_segment(x + 1 + movex + 50, y + movey, x + movex, y + movey, data);
			if (y > 0 && data.map[y][x] == 0 && data.map[y - 1][x] == 0)
				draw_segment(x + movex, y + movey, x + movex, y + movey - 50, data);*/
			if (x + 1 < data.map[y][0] && data.map[y][x] == 0 && data.map[y][x + 1] == 0)
				draw_segment(ix, iy, ix - TILE_WIDTH_HALF, iy, data);
			if (y > 0 && data.map[y][x] == 0 && data.map[y - 1][x] == 0)
				draw_segment(ix, iy, ix, iy - TILE_HEIGHT_HALF, data);
			movex += 50;
			x++;
		}
		movey += 50;
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
}

// screen.x = (map.x - map.y) * TILE_WIDTH_HALF;
// screen.y = (map.x + map.y) * TILE_HEIGHT_HALF;

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
			iy = (x + y) * TILE_HEIGHT_HALF;
			data.img.data[(iy + 250) * WIN_WIDTH + ix + 450] = 0xFFFFFF;
			x++;
		}
		//printf("\n");
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
}
