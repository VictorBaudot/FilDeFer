/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:44:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/30 13:44:46 by vbaudot          ###   ########.fr       */
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

void draw_segment(int x1, int y1, data_t *param)
{
	int x2;
	float a;
	int y2;
	int r;

	x2 = 500;
	y2 = 500;
	if (x2 - x1 == 0)
	{
		while (y1 <= y2)
		{
			mlx_pixel_put(param->mlx, param->win, x1, y1, 0x00FFFFFF);
			y1++;
		}
		return ;
	}
	a = float_abs(y2 - y1) / float_abs(x2 - x1);
	r = x1;
	while (y1 <= y2)
	{
		x1 = r;
		while (x1 < x2)
		{
			if ((float_abs(y1 - y2) / float_abs(x1 - x2)) == a)
				mlx_pixel_put(param->mlx, param->win, x1, y1, 0x00FFFFFF);
			x1++;
		}
		y1++;
	}
}
