/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:14:57 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/08 21:19:56 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	finish_print(t_list *beg, t_env *ptr)
{
	t_color	col;

	while (beg->next)
	{
		print_line(beg->pt, beg->next->pt, *ptr);
		beg = beg->next;
	}
	col.r = 0;
	col.g = 100;
	col.b = 255;
	fill_pixel(ptr->i_s, beg->pt.x, beg->pt.y, col);
}

void	print_list(t_env *ptr)
{
	t_list		*beg;
	t_list		*beg2;
	t_list_y	*issou;

	issou = ptr->begin;
	while (issou->next)
	{
		beg = issou->lst;
		issou = issou->next;
		beg2 = issou->lst;
		while (beg)
		{
			if (beg->next)
				print_line(beg->pt, beg->next->pt, *ptr);
			print_line(beg->pt, beg2->pt, *ptr);
			beg = beg->next;
			beg2 = beg2->next;
		}
	}
	beg = issou->lst;
	finish_print(beg, ptr);
}
