/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:28:49 by mporzier          #+#    #+#             */
/*   Updated: 2018/11/22 18:38:21 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	case_verti(t_window ptr, t_point xy, t_point inc, t_point d)
{
	int	cumul;
	int	k;

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
		mlx_pixel_put(ptr.mlx_ptr, ptr.win_ptr, xy.x, xy.y, 0xFFFFFFF);
		k++;
	}
}

void	case_horiz(t_window ptr, t_point xy, t_point inc, t_point d)
{
	int	cumul;
	int	k;

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
		mlx_pixel_put(ptr.mlx_ptr, ptr.win_ptr, xy.x, xy.y, 0xFFFFFFF);
		k++;
	}
}

void	print_line(t_point i, t_point f, t_window ptr)
{
	t_point		d;
	t_point		xy;
	t_point		inc;

	xy.x = i.x;
	xy.y = i.y;
	d.x = f.x - i.x;
	d.y = f.y - i.y;
	inc.x = (d.x > 0) ? 1 : -1;
	inc.y = (d.y > 0) ? 1 : -1;
	d.x = ft_abs(d.x);
	d.y = ft_abs(d.y);
	mlx_pixel_put(ptr.mlx_ptr, ptr.win_ptr, xy.x, xy.y, 0xFFFFFFF);
	if (d.x > d.y)
		case_horiz(ptr, xy, inc, d);
	else
		case_verti(ptr, xy, inc, d);
}
