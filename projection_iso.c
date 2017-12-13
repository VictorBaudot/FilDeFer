/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_iso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:32:15 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/13 15:33:59 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	create_point_f(t_pos t, t_data *data, int xf, int yf)
{
	t.xf = xf;
	t.yf = yf;
	data->mp = 0;
	draw_segment(t, *data);
}

void		projection_iso(t_data *data, int **map)
{
	int		x;
	int		y;
	t_pos	t;

	y = 0;
	while (map[y])
	{
		x = 1;
		while (x <= map[y][0])
		{
			t.xi = (x - y) * data->tile_width_half;
			t.yi = (x + y) * (data->tile_heigth_half / 2)
			- map[y][x] * data->depth;
			if (x > 1)
				create_point_f(t, data, ((x - 1) - y) * data->tile_width_half,
				(((x - 1) + y) * (data->tile_heigth_half / 2)) - map[y][x - 1]
				* data->depth);
			if (y > 0 && x < map[y][0] + 1)
				create_point_f(t, data, (x - (y - 1)) * data->tile_width_half,
				((x + (y - 1)) * (data->tile_heigth_half / 2)) - map[y - 1][x]
					* data->depth);
			x++;
		}
		y++;
	}
}
