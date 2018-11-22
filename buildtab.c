/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildtab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:07:58 by mporzier          #+#    #+#             */
/*   Updated: 2018/11/22 12:46:25 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	erase_number(char **str)
{
	int i;

	i = 0;
	while ((*str)[i] == ' ')
		i++;
	while ((*str)[i])
	{
		if ((*str)[i] == ' ')
			break ;
		(*str)[i] = ' ';
		i++;
	}
}

int		check_isempty(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		**build_tab(char *name, t_point *size)
{
	int		**tab;
	int		y;
	int		x;
	char	*line;
	int		fd;

	x = 0;
	y = 0;
	fd = open(name, O_RDONLY);
	tab = alloc_tab(name, size);
	while (y < size->y)
	{
		get_next_line(fd, &line);
		while (x < size->x)
		{
			tab[y][x] = ft_atoi(line);
			if (check_isempty(line) == 0)
				erase_number(&line);
			x++;
		}
		x = 0;
		y++;
	}
	return (tab);
}
