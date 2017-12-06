/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:58:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/06 14:43:23 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct    data_s
{
	void          	*mlx;
	void          	*win;
	t_img			img;
	int 			nb_lines;
	int 			win_width;
	int 			win_height;
	double 			tile_width_half;
	double 			tile_heigth_half;
	int 			depth;
}                 data_t;

int		**get_map(int fd, int *nb_lines);
int		my_key_funct(int keycode);
int		get_center_h(data_t data, int **map);
int		get_center_v(data_t data, int **map);
void	join_points(data_t data, int **map);
int		fdf_init(int **map, int nb_lines);
void	ft_error(void);
void	print_usage(void);
void	draw_segment(int x1, int y1, int x2, int y2, data_t data, int **map);

#endif
