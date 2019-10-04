/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:28:49 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/10 15:40:18 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	case_verti(t_points m, t_point xy, t_point inc, t_point d)
{
	int		cumul;
	int		k;

	k = 1;
	cumul = d.y / 2;
	while (k < d.y)
	{
		xy.y += inc.y;
		cumul += d.x;
		if (cumul >= d.y)
		{
			cumul -= d.y;
			xy.x += inc.x;
		}
		fill_pixel(m.ptr.i_s, xy.x, xy.y, calc_color(m));
		k++;
	}
}

void	case_horiz(t_points m, t_point xy, t_point inc, t_point d)
{
	int		cumul;
	int		k;

	k = 1;
	cumul = d.x / 2;
	while (k <= d.x)
	{
		xy.x += inc.x;
		cumul += d.y;
		if (cumul >= d.x)
		{
			cumul -= d.x;
			xy.y += inc.y;
		}
		fill_pixel(m.ptr.i_s, xy.x, xy.y, calc_color(m));
		k++;
	}
}

void	print_line(t_point i, t_point f, t_env ptr)
{
	t_point		d;
	t_point		xy;
	t_point		inc;
	t_points	m;

	m.a = i;
	m.b = f;
	m.ptr = ptr;
	xy.x = i.x;
	xy.y = i.y;
	d.x = f.x - i.x;
	d.y = f.y - i.y;
	inc.x = (d.x > 0) ? 1 : -1;
	inc.y = (d.y > 0) ? 1 : -1;
	d.x = ft_abs(d.x);
	d.y = ft_abs(d.y);
	fill_pixel(ptr.i_s, xy.x, xy.y, calc_color(m));
	if (d.x > d.y)
		case_horiz(m, xy, inc, d);
	else
		case_verti(m, xy, inc, d);
}
