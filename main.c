/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/02 15:55:12 by vbaudot          ###   ########.fr       */
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
		free(split[i]);
		i++;
	}
	free(split);
	return (tab);
}

int	**get_map(int fd, int *nb_lines)
{
	int **map;
	char *line;
	int i;

	i = 0;
	if (!(map = (int**)malloc(sizeof(map))))
		ft_error();
	while (get_next_line(fd, &line) == 1)
	{
		map[i] = ft_tab_atoi(ft_split_whitespaces(line));
		free(line);
		i++;
	}
	//free(line);
	*nb_lines = i;
	map[i] = 0;
	return (map);
}

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
	//while (42){}
	return (EXIT_SUCCESS);
}
