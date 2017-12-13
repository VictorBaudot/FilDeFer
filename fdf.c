/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:43:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/13 15:37:26 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		exit_x(void)
{
	exit(EXIT_SUCCESS);
}

static t_data	init_data_win_and_tiles(t_data data, int **map, int nb_lines)
{
	int	l;

	data.win_width = 1200;
	data.win_height = 1200;
	data.nb_lines = nb_lines;
	data.depth = 1;
	data.nb_cols = map[0][0];
	data.map = map;
	data.mp = 0;
	data.color = 0xFFFFFF;
	data.p = map[0][1];
	l = (data.nb_cols >= data.nb_lines) ? data.nb_cols : data.nb_lines;
	data.tile_width_half = (data.win_width - 200) / (l * 2);
	data.tile_heigth_half = (data.win_height - 200) / (l * 2);
	return (data);
}

int				fdf_init(int **map, int nb_lines)
{
	t_data	data;
	int		i;

	i = -1;
	if ((data.mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	data = init_data_win_and_tiles(data, map, nb_lines);
	if ((data.win = mlx_new_window(data.mlx, data.win_width, data.win_height,
		"Fil de Fer")) == NULL)
		exit(EXIT_FAILURE);
	data.img.img_ptr = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.img.data = (int *)mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
		&data.img.size_l, &data.img.endian);
	projection_iso(&data, map);
	/*while (++i < data.nb_lines)
		free(map[i]);*/
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
	mlx_string_put(data.mlx, data.win, 30, 50, 200, "Depth: ");
	mlx_string_put(data.mlx, data.win, 100, 50, 200, ft_itoa(data.depth));
	mlx_string_put(data.mlx, data.win, 30, 100, 200, "+/- to change it (1-4)");
	mlx_hook(data.win, 17, 1L << 17, exit_x, 0);
	mlx_key_hook(data.win, my_key_funct, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img.img_ptr);
	mlx_destroy_window(data.mlx, data.win);
	exit(EXIT_SUCCESS);
}
