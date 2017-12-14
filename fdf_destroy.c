/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:17:44 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/14 11:21:46 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_destroy(t_data *data)
{
	int i;

	i = -1;
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	while (++i < data->nb_lines)
		free(data->map[i]);
	exit(EXIT_SUCCESS);
}
