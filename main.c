/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/30 12:09:27 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct    data_s
{
	void          *mlx;
	void          *win;
	int 		  color;
}                 data_t;

void draw_carre(int x, int y, int color, data_t *param)
{
	int r;

	r = x;
	while (y < 150)
	{
		x = r;
		while (x < 150)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, color);
			x++;
		}
		y++;
	}
}

int	my_key_funct(int keycode, data_t *param)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 15)
		draw_carre(50, 50, param->color, param);
	if (keycode == 9)
		draw_carre(50, 50, 0x0000FF00, param);
	if (keycode == 11)
		draw_carre(50, 50, 0x000000FF, param);
	param->color += 100;
	return (0);
}

int main(void)
{
	data_t	*data;

	data = (data_t*)malloc(sizeof(data));
	data->color = 1;
	if ((data->mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data->win = mlx_new_window(data->mlx, 600, 600, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	draw_carre(50, 50, 0x00FFFFFF, data);
	mlx_key_hook(data->win, my_key_funct, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
