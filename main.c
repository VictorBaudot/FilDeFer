/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/07 16:42:57 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
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
		fdf_init(map, nb_lines);
		while (++i < nb_lines)
			free(map[i]);
	}
	else
		print_usage();
	return (EXIT_SUCCESS);
}
