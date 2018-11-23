/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:11:55 by mporzier          #+#    #+#             */
/*   Updated: 2018/11/22 19:02:22 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_window	ptr;
	t_point		size;
	t_point		**matrix;

	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 1000, 1000, "COUCOU");
	matrix = convert_tab(build_tab(av[1], &size), size);
	print_matrix(ptr, matrix, size);
	mlx_loop(ptr.mlx_ptr);
	return (0);
}








