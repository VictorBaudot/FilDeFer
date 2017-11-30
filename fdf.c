/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:43:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/30 13:48:32 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_key_funct(int keycode, data_t *param)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 13)
		draw_carre(200, 200, 0x00FFFFFF, param);
	if (keycode == 2)
		draw_carre(200, 200, 0x00000000, param);
	if (keycode == 15)
		draw_carre(200, 200, 0x00FF0000, param);
	if (keycode == 9)
		draw_carre(200, 200, 0x0000FF00, param);
	if (keycode == 11)
		draw_carre(200, 200, 0x000000FF, param);
	if (keycode == 83)
		draw_segment(50, 50, param);
	if (keycode == 84)
		draw_segment(50, 500, param);
	return (0);
}

int fdf_init(void)
{
	data_t	*data;

	data = (data_t*)malloc(sizeof(data));
	if ((data->mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data->win = mlx_new_window(data->mlx, 600, 600, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	mlx_key_hook(data->win, my_key_funct, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
