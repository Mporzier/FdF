/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:56:11 by mporzier          #+#    #+#             */
/*   Updated: 2018/11/22 18:57:18 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_matrix(t_window ptr, t_point **matrix, t_point size)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < size.y)
	{
		while (x < size.x - 1)
		{
			print_line(matrix[y][x], matrix[y][x + 1], ptr);
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
	while (x < size.x)
	{
		while (y < size.y - 1)
		{
			print_line(matrix[y][x], matrix[y + 1][x], ptr);
			y++;
		}
		y = 0;
		x++;
	}
}













