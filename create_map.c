/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:02:17 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/06 14:47:47 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	nb_elems(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static int	*ft_tab_atoi(char **split)
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

int			**get_map(int fd, int *nb_lines)
{
	int		**map;
	char	*line;
	int		i;

	i = 0;
	if (!(map = (int**)malloc(sizeof(map))))
		ft_error();
	while (get_next_line(fd, &line) == 1)
	{
		map[i] = ft_tab_atoi(ft_split_whitespaces(line));
		if (map[i][0] != map[0][0])
			ft_error();
		free(line);
		i++;
	}
	*nb_lines = i;
	map[i] = 0;
	return (map);
}
