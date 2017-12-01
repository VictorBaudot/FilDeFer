/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:44:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/01 17:53:03 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float float_abs(int n)
{
	return ((n < 0) ? (float)-n : (float)n);
}

void draw_carre(int x, int y, int color, data_t *param)
{
	int r;

	r = x;
	while (y < 400)
	{
		x = r;
		while (x < 400)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, color);
			x++;
		}
		y++;
	}
}

void draw_segment(int x1, int y1, int x2, int y2, data_t data)
{
	float a;
	int r;

	if (x2 - x1 == 0)
	{
		if (y1 <= y2)
			while (y1 <= y2)
			{
				data.img.data[(y1 + 250) * WIN_WIDTH + x1 + 450] = 0xFFFFFF;
				y1++;
			}
		else if (y2 <= y1)
			while (y2 <= y1)
			{
				data.img.data[(y2 + 250) * WIN_WIDTH + x2 + 450] = 0xFFFFFF;
				y2++;
			}
		return ;
	}
	if (x1 < x2)
	{
		a = float_abs(y2 - y1) / float_abs(x2 - x1);
		r = x1;
		while (y1 <= y2)
		{
			x1 = r;
			while (x1 < x2)
			{
				if ((float_abs(y1 - y2) / float_abs(x1 - x2)) == a)
					data.img.data[(y1 + 250) * WIN_WIDTH + x1 + 450] = 0xFFFFFF;
				x1++;
			}
			y1++;
		}
	}
	else
	{
		a = float_abs(y1 - y2) / float_abs(x1 - x2);
		r = x2;
		while (y2 <= y1)
		{
			x2 = r;
			while (x2 < x1)
			{
				if ((float_abs(y2 - y1) / float_abs(x2 - x1)) == a)
					data.img.data[(y2 + 250) * WIN_WIDTH + x2 + 450] = 0xFFFFFF;
				x2++;
			}
			y2++;
		}
	}
}
