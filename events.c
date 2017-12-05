/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:00:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/05 09:08:53 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_key_funct(int keycode, data_t *data)
{
	int i;

	i = -1;
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		mlx_destroy_window(data->mlx, data->win);
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
		while (42){}
		exit(EXIT_SUCCESS);
	}
	if (keycode == 82)
		all_black(*data);
	if (keycode == 83)
		print_map_points(*data);
	if (keycode == 84)
		join_points(*data);
	return (0);
}
