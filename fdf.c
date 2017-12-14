/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:43:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/14 11:20:37 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void			proj_init(t_data *data)
{
	char *depth;

	projection_iso(data, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	mlx_string_put(data->mlx, data->win, 30, 50, 0xFFFFFF, "Depth: ");
	depth = ft_itoa(data->depth);
	mlx_string_put(data->mlx, data->win, 100, 50, 0xFFFFFF, depth);
	free(depth);
	mlx_string_put(data->mlx, data->win, 30, 100, 0xFFFFFF,
		"[-+] change depth");
	mlx_string_put(data->mlx, data->win, 30, 150, 0xFFFFFF,
		"[pm] points/map view");
	mlx_string_put(data->mlx, data->win, 30, 200, 0xFFFFFF,
		"[wrgb] white/red/green/blue");
}

int				fdf_init(int **map, int nb_lines)
{
	t_data	data;

	if ((data.mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	data = init_data_win_and_tiles(data, map, nb_lines);
	if ((data.win = mlx_new_window(data.mlx, data.win_width, data.win_height,
		"Fil de Fer")) == NULL)
		exit(EXIT_FAILURE);
	data.img.img_ptr = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.img.data = (int *)mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
		&data.img.size_l, &data.img.endian);
	proj_init(&data);
	mlx_hook(data.win, 17, 1L << 17, fdf_destroy, &data);
	mlx_key_hook(data.win, my_key_funct, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img.img_ptr);
	mlx_destroy_window(data.mlx, data.win);
	exit(EXIT_SUCCESS);
}
