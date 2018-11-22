/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloctab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:25:44 by mporzier          #+#    #+#             */
/*   Updated: 2018/11/22 11:26:12 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_nb(char *str)
{
	int i;
	int	size;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0' && str[i])
		{
			while (str[i] <= '9' && str[i] >= '0' && str[i])
				i++;
			size++;
		}
		if (str[i])
			i++;
	}
	return (size);
}

int		count_lines(char *name)
{
	int		fd;
	int		i;
	int		size;
	char	*line;

	i = 1;
	size = 0;
	fd = open(name, O_RDONLY);
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		if (i == 0)
			break ;
		size++;
	}
	close(fd);
	return (size);
}

int		malloc_tab(char *name, int size, int ***tab)
{
	int		fd;
	int		k;
	int		i;
	char	*line;

	i = 1;
	k = 0;
	fd = open(name, O_RDONLY);
	while (size >= 0)
	{
		i = get_next_line(fd, &line);
		printf("%s | %d | %d | %d\n", line, count_nb(line), size, k);
		if (!(*tab[size] = (int*)malloc(sizeof(int) * (count_nb(line)))))
			return (1);
		size--;
	}
	close(fd);
	return (0);
}

int		**alloc_tab(char *name, t_point *size)
{
	int		**tab;
	char	*line;
	int		i;
	int		fd;

	i = 0;
	i = count_lines(name);
	size->y = i;
	if (!(tab = (int**)malloc(sizeof(int*) * (i))))
		return (NULL);
	fd = open(name, O_RDONLY);
	while (i > 0)
	{
		i--;
		get_next_line(fd, &line);
		size->x = count_nb(line);
		if (!(tab[i] = (int*)malloc(sizeof(int) * (count_nb(line)))))
			return (NULL);
	}
	close(fd);
	return (tab);
}
