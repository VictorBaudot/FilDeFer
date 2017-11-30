/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/30 15:39:38 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int nb_elems(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int *ft_tab_atoi(char **split)
{
	int i;
	int *tab;
	int nb;

	i = 0;
	nb = nb_elems(split);
	tab = (int *)malloc(sizeof(int) * (nb + 1));
	tab[i] = nb;
	while (split[i] != 0)
	{
		tab[i + 1] = ft_atoi(split[i]);
		i++;
	}
	return (tab);
}

int	**get_map(int fd)
{
	int **map;
	int ret;
	char *line;
	int i;

	i = 0;
	if (!(map = (int**)malloc(sizeof(map))))
		ft_error();
	while ((ret = get_next_line(fd, &line)) == 1)
	{
	//	printf("%s\n", line);
		map[i] = ft_tab_atoi(ft_split_whitespaces(line));
		free(line);
		i++;
	}
	map[i] = 0;
	return (map);
}

void print_map_points(int **map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 1;
		while (x < map[y][0])
		{
			//printf("%d ", map[y][x]);
			x++;
		}
		//printf("\n");
		y++;
	}
}

int main(int ac, char **av)
{
	int		fd;
	int		**map;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (1);
		map = get_map(fd);
		print_map_points(map);
		close(fd);
	}
	else
		print_usage();
	return (EXIT_SUCCESS);
}
