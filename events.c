/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:00:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/13 15:49:50 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_key_funct(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	if (key == 13 || key == 5 || key == 15 || key == 11 || key == 46 ||
		key == 35 || key == 78 || key == 69)
		all_black(*data);
	if (key == 11)
		data->color = 0xff;
	if (key == 13)
		data->color = 0xFFFFFF;
	if (key == 15)
		data->color = 0xff0000;
	if (key == 5)
		data->color = 0x00ff00;
	if (key == 46)
		projection_iso(data, data->map);
	if (key == 35)
		print_iso_points(data);
	if (key == 69 && data->depth < 4)
		data->depth++;
	if (key == 78 && data->depth > 1)
		data->depth--;
	(key == 13 || key == 5 || key == 15 || key == 11 || key == 78
		|| key == 69) ? ((data->mp == 0) ?
	projection_iso(data, data->map) : print_iso_points(data)) : 0;
	if (key == 13 || key == 5 || key == 15 || key == 11 || key == 46 || key == 35 || key == 78 || key == 69)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
		mlx_string_put(data->mlx, data->win, 30, 50, 0xFFFFFF, "Depth: ");
		mlx_string_put(data->mlx, data->win, 100, 50, 0xFFFFFF, ft_itoa(data->depth));
		mlx_string_put(data->mlx, data->win, 30, 100, 0xFFFFFF, "[-+] change depth");
		mlx_string_put(data->mlx, data->win, 30, 150, 0xFFFFFF, "[pm] points/map view");
		mlx_string_put(data->mlx, data->win, 30, 200, 0xFFFFFF, "[wrgb] white/red/green/blue");
	}
	return (0);
}
