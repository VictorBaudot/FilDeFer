/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/14 11:05:41 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	**check_alts(int **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 1;
		while (x <= map[y][0])
		{
			if (map[y][x] < -100)
				map[y][x] = -100;
			else if (map[y][x] > 100)
				map[y][x] = 100;
			x++;
		}
		y++;
	}
	return (map);
}

int			main(int ac, char **av)
{
	int		fd;
	int		**map;
	int		i;
	int		nb_lines;

	i = -1;
	nb_lines = 0;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ft_error();
		map = get_map(av[1], fd, &nb_lines);
		map = check_alts(map);
		fdf_init(map, nb_lines);
		while (++i < nb_lines)
			free(map[i]);
	}
	else
		print_usage();
	return (EXIT_SUCCESS);
}
