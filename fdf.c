/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:43:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/01 16:59:21 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_key_funct(int keycode, data_t *data)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 83)
		print_map_points(*data);
	if (keycode == 84)
		join_points(*data);
	return (0);
}

int fdf_init(int **map)
{
	data_t	data;
/*	int		count_w;
	int		count_h;

	count_h = -1;*/
	if ((data.mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	if ((data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Fil de Fer")) == NULL)
		exit(EXIT_FAILURE);
	data.img.img_ptr = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.map = (int**)malloc(sizeof(map));
	if ((data.map = map) == NULL)
		exit(EXIT_FAILURE);
	data.img.data = (int *)mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
		&data.img.size_l, &data.img.endian);
//	print_map_points(data);
//	join_points(data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
	mlx_key_hook(data.win, my_key_funct, &data);
	mlx_loop(data.mlx);
	/*

	mlx_loop(data.mlx);*/
//	free(data->map);
	//free(data);
	exit(EXIT_SUCCESS);
}
