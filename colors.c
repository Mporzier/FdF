/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:58:19 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/10 17:38:23 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color		ft_blue(void)
{
	t_color col;

	col.r = 0;
	col.g = 100;
	col.b = 255;
	return (col);
}

t_color		ft_green(void)
{
	t_color col;

	col.r = 100;
	col.g = 200;
	col.b = 0;
	return (col);
}

t_color		ft_brown(void)
{
	t_color col;

	col.r = 87;
	col.g = 59;
	col.b = 12;
	return (col);
}

t_color		ft_small(void)
{
	t_color col;

	col.r = 205;
	col.g = 133;
	col.b = 63;
	return (col);
}

t_color		calc_color(t_points m)
{
	t_color		col;

	if ((m.a.h == 0 && m.b.h == 0) || m.a.h < 0 || m.b.h < 0)
		col = ft_blue();
	else if (m.a.h < 8 && m.b.h < 8)
	{
		col.r = 255;
		col.g = 255;
		col.b = 180;
	}
	else if (m.a.h < 30 && m.b.h < 30)
		col = ft_green();
	else if (m.a.h < 80 && m.b.h < 80)
		col = ft_small();
	else if (m.a.h < 140 && m.b.h < 140)
	{
		col.r = 150;
		col.g = 120;
		col.b = 40;
	}
	else
		col = ft_brown();
	return (col);
}
