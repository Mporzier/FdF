/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:56:11 by mporzier          #+#    #+#             */
/*   Updated: 2018/11/22 15:33:03 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_matrix(t_window ptr, t_point **matrix, t_point size)
{
	t_point origin;
	t_point	a;

	origin.x = ORIGIN_X;
	origin.y = ORIGIN_Y;
	a.x = 480;
	a.y = 960;
	print_line(a, origin, ptr);
}













