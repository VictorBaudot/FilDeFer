/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/05 09:04:01 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	int		fd;
	int		**map;
	int		i;
	int 	nb_lines;

	i = -1;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (1);
		map = get_map(fd, &nb_lines);
		fdf_init(map, nb_lines);
		while (map[++i])
			free(map[i]);
		free(map);
		close(fd);
	}
	else
		print_usage();
	return (EXIT_SUCCESS);
}
