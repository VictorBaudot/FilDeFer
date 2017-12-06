/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:38:51 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/06 14:52:24 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	join_points(data_t data, int **map)
{
	int x;
	int ix;
	int y;
	int iy;

	y = 0;
	while (map[y])
	{
		x = 1;
		while (x < map[y][0])
		{
			ix = (x - y) * data.tile_width_half;
			iy = (x + y) * (data.tile_heigth_half / 2) - map[y][x] * data.depth;
			if (x > 1)
				draw_segment(ix, iy, ((x - 1) - y) * data.tile_width_half,
				(((x - 1) + y) * (data.tile_heigth_half / 2)) - map[y][x - 1]
				* data.depth, data, map);
			if (y > 0 && x < map[y][0] + 1)
				draw_segment(ix, iy, (x - (y - 1)) * data.tile_width_half,
				((x + (y - 1)) * (data.tile_heigth_half / 2)) - map[y - 1][x]
				* data.depth, data, map);
			x++;
		}
		y++;
	}
}
