/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:07:08 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/03 14:07:23 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_color(int alt)
{
	if (alt == 0)
		return (0x29C815);
	else if (alt > 0)
		return (0x6A4706);
	else
		return (0x0036FE);
}

void all_black(data_t data)
{
	int x;
	int y;

	y = 0;
	while (y < data.win_height)
	{
		x = 0;
		while (x < data.win_width)
		{
			data.img.data[y * data.win_width + x] = 0x000000;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
}
