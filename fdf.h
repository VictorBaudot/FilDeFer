/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:58:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/01 17:43:48 by vbaudot          ###   ########.fr       */
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

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200
# define TILE_WIDTH_HALF 25
# define TILE_HEIGHT_HALF 25

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
	int			  	**map;
}                 data_t;

void	join_points(data_t data);
void	print_map_points(data_t data);
int		fdf_init(int **map);
float	float_abs(int n);
void	ft_error(void);
void	print_usage(void);
void	draw_carre(int x, int y, int color, data_t *param);
void	draw_segment(int x1, int y1, int x2, int y2, data_t data);

#endif
