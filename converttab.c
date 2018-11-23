/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:46:46 by mporzier          #+#    #+#             */
/*   Updated: 2018/11/22 18:59:45 by mporzier         ###   ########.fr       */
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
	int i;
	int k;

	y = 0;
	x = 0;
	matrix = alloc_matrix(size.x, size.y);
	while (y < size.y)
	{
		while (x < size.x)
		{
			matrix[y][x].height = tab[y][x];
			matrix[y][x].x = ORI_X + x * 20 - y * 20;
			matrix[y][x].y = ORI_Y + x * 20 + y * 20 - matrix[y][x].height * 3;
			x++;
		}
		x = 0;
		y++;
	}
	return (matrix);
}






















