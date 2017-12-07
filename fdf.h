/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:58:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/07 16:48:21 by vbaudot          ###   ########.fr       */
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

typedef struct	s_pos
{
	int			xi;
	int			yi;
	int			xf;
	int			yf;
}				t_pos;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			nb_lines;
	int			nb_cols;
	int			win_width;
	int			win_height;
	double		tile_width_half;
	double		tile_heigth_half;
	int			depth;
	int			p;
}				t_data;

int				**get_map(char *av, int fd, int *nb_lines);
int				my_key_funct(int keycode, t_data *data);
int				get_center_h(t_data data);
int				get_center_v(t_data data);
void			join_points(t_data data, int **map);
int				fdf_init(int **map, int nb_lines);
void			ft_error(void);
void			print_usage(void);
void			draw_segment(t_pos t, t_data data);

#endif
