/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:43:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/06 14:48:51 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static data_t	init_data_win_and_tiles(data_t data, int **map)
{
	int	l;

	data.win_width = 1200;
	data.win_height = 1200;
	data.depth = 2;
	l = (map[0][0] >= data.nb_lines) ? map[0][0] : data.nb_lines;
	data.tile_width_half = (data.win_width - 200) / (l * 2);
	data.tile_heigth_half = (data.win_height - 200) / (l * 2);
	return (data);
}

int				fdf_init(int **map, int nb_lines)
{
	data_t	data;
	int		i;

	i = -1;
	if ((data.mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	data.nb_lines = nb_lines;
	data = init_data_win_and_tiles(data, map);
	if ((data.win = mlx_new_window(data.mlx, data.win_width, data.win_height,
		"Fil de Fer")) == NULL)
		exit(EXIT_FAILURE);
	data.img.img_ptr = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.img.data = (int *)mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
		&data.img.size_l, &data.img.endian);
	join_points(data, map);
	while (++i < data.nb_lines)
		free(map[i]);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
	mlx_key_hook(data.win, my_key_funct, 0);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img.img_ptr);
	mlx_destroy_window(data.mlx, data.win);
	exit(EXIT_SUCCESS);
}
