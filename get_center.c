/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:28:55 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/06 16:14:55 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_center_h(t_data data)
{
	int pos_h;

	pos_h = ((data.nb_cols - 1) * data.tile_width_half) + ((data.nb_lines - 1)
	* data.tile_heigth_half);
	pos_h = data.win_width - pos_h;
	pos_h /= 2;
	pos_h += ((data.nb_lines - 1) * data.tile_heigth_half);
	return (pos_h);
}

int	get_center_v(t_data data)
{
	int pos_v;

	pos_v = (1 + 0) * (data.tile_heigth_half / 2) - data.p * 2;
	pos_v += (data.nb_cols + data.nb_lines - 1)
	* (data.tile_heigth_half / 2);
	pos_v = data.win_height - pos_v;
	pos_v /= 2;
	return (pos_v);
}
