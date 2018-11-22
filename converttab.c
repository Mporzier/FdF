/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:46:46 by mporzier          #+#    #+#             */
/*   Updated: 2018/11/22 14:32:47 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**alloc_matrix(int x, int y)
{
	t_point		**matrix;
	int			i;

	i = 0;
	if (!(matrix = (t_point**)malloc(sizeof(t_point*) * (y))))
		return (NULL);
	while (i < x)
	{
		if (!(matrix[i] = (t_point*)malloc(sizeof(t_point) * x)))
			return (NULL);
		i++;
	}
	return (matrix);
}

t_point		**convert_tab(int **tab, t_point size)
{
	int		x;
	int		y;
	t_point	**matrix;

	y = 0;
	x = 0;
	matrix = alloc_matrix(size.x, size.y);
	while (y < size.y)
	{
		while (x < size.x)
		{
			matrix[y][x].height = tab[y][x];
			matrix[y][x].x = x;
			matrix[y][x].y = y;
			x++;
		}
		x = 0;
		y++;
	}
	return (matrix);
}






















