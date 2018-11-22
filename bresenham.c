/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:28:49 by mporzier          #+#    #+#             */
/*   Updated: 2018/11/22 14:52:21 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		assign_value(int i)
{
	if (i > 0)
		return (1);
	else
		return (-1);
}

void	print_horizontal(t_point d, t_point a, t_point b, t_window ptr)
{
	t_point inc;
	int		i;
	int		cumul;

	cumul = d.x / 2;
	inc.x = assign_value(d.x);
	inc.y = assign_value(d.y);
	i = 1;
	while (i < d.x)
	{
		a.x += inc.x;
		cumul += d.y;
		if (cumul >= d.x)
		{
			cumul -= d.x;
			a.y += inc.y;
		}
		mlx_pixel_put(ptr.mlx_ptr, ptr.win_ptr, a.x, a.y, 0xFFFFFFF);
		i++;
	}
}

void	print_vertical(t_point d, t_point a, t_point b, t_window ptr)
{
	t_point	inc;
	int		i;
	int		cumul;

	cumul = d.y / 2;
	inc.x = assign_value(d.x);
	inc.y = assign_value(d.y);
	i = 1;
	while (i < d.y)
	{
		a.y += inc.y;
		cumul += d.x;
		if (cumul >= d.y)
		{
			cumul -= d.y;
			a.x += inc.x;
		}
		mlx_pixel_put(ptr.mlx_ptr, ptr.win_ptr, a.x, a.y, 0xFFFFFFF);
		i++;
	}
}

void	print_line(t_point a, t_point b, t_window ptr)
{
	t_point	d;

	d.x = ft_abs(b.x - a.x);
	d.y = ft_abs(b.y - a.y);
	if (d.x > d.y)
		print_horizontal(d, a, b, ptr);
	else
		print_vertical(d, a, b, ptr);
}
