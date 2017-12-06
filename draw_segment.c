/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:44:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/06 14:57:09 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_segment(int xi, int yi, int xf, int yf, data_t data, int **map)
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;

	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	data.img.data[(y + get_center_v(data, map)) * data.win_width + x + get_center_h(data, map)] = 0xFFFFFF;
	if (dx > dy)
	{
		cumul = dx / 2;
		i = 0;
		while (++i <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			data.img.data[(y + get_center_v(data, map)) * data.win_width + x + get_center_h(data, map)] = 0xFFFFFF;
		}
	}
	else
	{
		cumul = dy / 2;
		i = 0;
		while (++i <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			data.img.data[(y + get_center_v(data, map)) * data.win_width + x + get_center_h(data, map)] = 0xFFFFFF;
		}
	}
}
