/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:43:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/05 09:00:43 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

data_t init_data_win_and_tiles(data_t data)
{
	int l;

	data.win_width = 1200;
	data.win_height = 1200;
	data.depth = 2;
	l = (data.map[0][0] >= data.nb_lines) ? data.map[0][0] : data.nb_lines;
	data.tile_width_half = (data.win_width - 200) / (l * 2);
	data.tile_heigth_half = (data.win_height - 200) / (l * 2);
	return (data);
}

int fdf_init(int **map, int nb_lines)
{
	data_t	data;

	if ((data.mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	data.nb_lines = nb_lines;
	data.map = (int**)malloc(sizeof(map));
	if ((data.map = map) == NULL)
		exit(EXIT_FAILURE);
	data = init_data_win_and_tiles(data);
	if ((data.win = mlx_new_window(data.mlx, data.win_width, data.win_height,
		"Fil de Fer")) == NULL)
		exit(EXIT_FAILURE);
	data.img.img_ptr = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.img.data = (int *)mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
		&data.img.size_l, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
	mlx_key_hook(data.win, my_key_funct, &data);
	mlx_loop(data.mlx);
	exit(EXIT_SUCCESS);
}
