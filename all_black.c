/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_black.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:56:55 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/13 15:38:37 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	all_black(t_data data)
{
	int		x;
	int		y;

	y = 0;
	while (y <= data.win_height)
	{
		x = 1;
		while (x <= data.win_width)
		{
			data.img.data[x * data.win_width + y] = 0;
			x++;
		}
		y++;
	}
}
