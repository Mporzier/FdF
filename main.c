/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:41:01 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/10 17:26:44 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(unsigned char *i_s, int x, int y, t_color col)
{
	int i;

	i = 4 * SIZE_X * y + x * 4;
	i_s[i++] = col.b;
	i_s[i++] = col.g;
	i_s[i++] = col.r;
	i_s[i++] = 0;
}

void	create_window(t_env *ptr)
{
	int b;
	int s;
	int e;

	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 2500, 1300, "FdF");
	ptr->i_p = mlx_new_image(ptr->mlx, SIZE_X, SIZE_Y);
	ptr->i_s = (unsigned char*)mlx_get_data_addr(ptr->i_p, &(b), &(s), &(e));
	print_list(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->i_p, ptr->o.x, ptr->o.y);
	mlx_key_hook(ptr->win, key_events, ptr);
	mlx_loop(ptr->mlx);
}

int		main(int ac, char **av)
{
	t_env		ptr;

	if (ac != 2)
		return (error_msg(1));
	if (checkerrors(av[1], &ptr) == 1)
		return (error_msg(0));
	ptr.name = av[1];
	ptr.status = 1;
	ptr.o.x = -OX + 750;
	ptr.o.y = -OY + 150;
	ptr.sc.x = 2;
	ptr.sc.y = 1;
	ptr.begin = create_list(av[1], &ptr);
	create_window(&ptr);
	ft_lstsuppr(&(ptr.begin));
	return (0);
}
