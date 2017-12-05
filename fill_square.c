/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:39:28 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/05 09:18:49 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Pour plus tard gerer les lignes cachees

static int get_y_min(t_square square)
{
	int ymin;

	ymin = (square.a.y < square.b.y) ? square.a.y : square.b.y;
	ymin = (ymin < square.c.y) ? ymin : square.c.y;
	ymin = (ymin < square.d.y) ? ymin : square.d.y;
	return (ymin);
}

static int get_y_max(t_square square)
{
	int ymax;

	ymax = (square.a.y > square.b.y) ? square.a.y : square.b.y;
	ymax = (ymax > square.c.y) ? ymax : square.c.y;
	ymax = (ymax > square.d.y) ? ymax : square.d.y;
	return (ymax);
}

void fill_square(t_square square/*, data_t data, int color*/)
{
	int ymin;
	int ymax;
	int xmin;
	int xmax;
	int x;

	ymin = get_y_min(square) + 1;
	ymax = get_y_max(square);
	xmin = (square.c.x < square.b.x) ? square.c.x : square.b.x;
	xmax = (square.c.x > square.b.x) ? square.c.x : square.b.x;
//	printf("ymin:%d ymax:%d xmin:%d xmax:%d\n", ymin, ymax, xmin, xmax);
	if (ymin > ymax || xmin > xmax)
		printf("\n*********************************\nERRROR\n*****************************\n");
	while (ymin < ymax)
	{
		x = xmin + 1;
		while (x < xmax)
		{
			if ()
			x++;
		}
		ymin++;
	}
}
