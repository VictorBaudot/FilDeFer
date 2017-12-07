/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:44:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/07 13:36:42 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		f1(t_data data, int *tab, int dx, int dy)
{
	int cumul;
	int xinc;
	int yinc;
	int i;

	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	cumul = dx / 2;
	i = 0;
	while (++i <= dx)
	{
		tab[0] += xinc;
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			tab[1] += yinc;
		}
		data.img.data[(tab[1] + get_center_v(data)) * data.win_width + tab[0]
		+ get_center_h(data)] = 0xFFFFFF;
	}
}

static void		f2(t_data data, int *tab, int dx, int dy)
{
	int cumul;
	int xinc;
	int yinc;
	int i;

	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	cumul = dy / 2;
	i = 0;
	while (++i <= dy)
	{
		tab[1] += yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			tab[0] += xinc;
		}
		data.img.data[(tab[1] + get_center_v(data)) * data.win_width + tab[0]
		+ get_center_h(data)] = 0xFFFFFF;
	}
}

void			draw_segment(t_pos t, t_data data)
{
	int dx;
	int dy;
	int tab[2];

	tab[0] = t.xi;
	tab[1] = t.yi;
	dx = t.xf - t.xi;
	dy = t.yf - t.yi;
	data.img.data[(tab[1] + get_center_v(data)) * data.win_width
	+ tab[0] + get_center_h(data)] = 0xFFFFFF;
	if (abs(dx) > abs(dy))
		f1(data, tab, dx, dy);
	else
		f2(data, tab, dx, dy);
}
