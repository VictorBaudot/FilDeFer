/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:23:01 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/30 08:44:13 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_and_fill(int fd, char **tab)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		size;

	size = 3;
	ft_bzero(buf, BUFF_SIZE);
	while (!(ft_strchr(tab[fd], '\n')) && (size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		tmp = tab[fd];
		CHECK(!(tab[fd] = ft_strjoin(tab[fd], buf)));
		ft_strdel(&tmp);
	}
	return (size);
}

int			get_next_line(const int fd, char **line)
{
	static char	*tab[OPEN_MAX + 1];
	char		*tmp;
	int			ret;

	CHECK(fd < 0 || line == NULL || fd > OPEN_MAX);
	CHECK(tab[fd] == NULL && (tab[fd] = ft_strnew(0)) == NULL);
	CHECK((ret = ft_read_and_fill(fd, tab)) == -1);
	if (ret == 0)
	{
		CHECK(!(*line = ft_strdup(tab[fd])));
		ft_strdel(tab + fd);
		return (ft_strlen(*line) ? 1 : 0);
	}
	CHECK(!(*line = ft_strsub(tab[fd], 0, ft_strchr(tab[fd], '\n') - tab[fd])));
	tmp = tab[fd];
	CHECK(!(tab[fd] = ft_strdup(ft_strchr(tab[fd], '\n') + 1)));
	ft_strdel(&tmp);
	return (1);
}
