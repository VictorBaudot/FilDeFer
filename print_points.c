/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:04:30 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/13 15:38:54 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_iso_points(t_data *data)
{
	int x;
	int ix;
	int iy;
	int y;

	y = 0;
	data->mp = 1;
	while (data->map[y])
	{
		x = 1;
		while (x < data->map[y][0])
		{
			ix = (x - y) * data->tile_width_half;
			iy = (x + y) * data->tile_heigth_half / 2
			- data->map[y][x] * data->depth;
			data->img.data[(iy + get_center_v(*data)) * data->win_width
			+ ix + get_center_h(*data)] = data->color;
			x++;
		}
		y++;
	}
}
