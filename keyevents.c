/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevents.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:36:49 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/10 17:43:37 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_scale(t_env *ptr, int key)
{
	int b;
	int s;
	int e;

	if (key == 83 && ptr->sc.y < 8 * ptr->sc.x)
		ptr->sc.y *= 2;
	if (key == 86 && ptr->sc.y > 1)
		ptr->sc.y /= 2;
	mlx_destroy_image(ptr->mlx, ptr->i_p);
	ft_lstsuppr(&(ptr->begin));
	if (ptr->status == 1)
		ptr->begin = create_list(ptr->name, ptr);
	else
		ptr->begin = create_list2(ptr->name, ptr);
	ptr->i_p = mlx_new_image(ptr->mlx, SIZE_X, SIZE_Y);
	ptr->i_s = (unsigned char*)mlx_get_data_addr(ptr->i_p, &(b), &(s), &(e));
	print_list(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->i_p, ptr->o.x, ptr->o.y);
}

void	zoom_image(t_env *ptr, int key)
{
	int b;
	int s;
	int e;

	if (key == 69 && ptr->sc.x < 8)
	{
		ptr->sc.x *= 2;
		ptr->sc.y *= 2;
	}
	if (key == 78 && ptr->sc.x > 2)
	{
		ptr->sc.x /= 2;
		ptr->sc.y /= 2;
	}
	mlx_destroy_image(ptr->mlx, ptr->i_p);
	ft_lstsuppr(&(ptr->begin));
	if (ptr->status == 1)
		ptr->begin = create_list(ptr->name, ptr);
	else
		ptr->begin = create_list2(ptr->name, ptr);
	ptr->i_p = mlx_new_image(ptr->mlx, SIZE_X, SIZE_Y);
	ptr->i_s = (unsigned char*)mlx_get_data_addr(ptr->i_p, &(b), &(s), &(e));
	print_list(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->i_p, ptr->o.x, ptr->o.y);
}

void	change_view(t_env *ptr)
{
	int	b;
	int	s;
	int	e;

	mlx_destroy_image(ptr->mlx, ptr->i_p);
	ft_lstsuppr(&(ptr->begin));
	if (ptr->status == 0)
	{
		ptr->begin = create_list(ptr->name, ptr);
		ptr->status = 1;
	}
	else
	{
		ptr->begin = create_list2(ptr->name, ptr);
		ptr->status = 0;
	}
	ptr->i_p = mlx_new_image(ptr->mlx, SIZE_X, SIZE_Y);
	ptr->i_s = (unsigned char*)mlx_get_data_addr(ptr->i_p, &(b), &(s), &(e));
	print_list(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->i_p, ptr->o.x, ptr->o.y);
}

void	move_image(t_env *ptr, int key)
{
	if (key == 82)
	{
		ptr->o.x = -OX + 750;
		ptr->o.y = -OY + 150;
	}
	if (key == 123)
		ptr->o.x -= 100;
	if (key == 124)
		ptr->o.x += 100;
	if (key == 125)
		ptr->o.y += 100;
	if (key == 126)
		ptr->o.y -= 100;
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->i_p, ptr->o.x, ptr->o.y);
}

int		key_events(int key, t_env *ptr)
{
	if (key == 53)
	{
		ft_lstsuppr(&ptr->begin);
		exit(0);
	}
	if ((key >= 123 && key <= 126) || key == 82)
		move_image(ptr, key);
	if (key == 69 || key == 78)
		zoom_image(ptr, key);
	if (key == 83 || key == 86)
		change_scale(ptr, key);
	if (key == 65)
		change_view(ptr);
	return (0);
}
