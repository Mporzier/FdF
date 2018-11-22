/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:12:16 by mporzier          #+#    #+#             */
/*   Updated: 2018/11/22 15:32:14 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include <mlx.h>
# define ORIGIN_X 500
# define ORIGIN_Y 980

typedef	struct		s_point
{
	int x;
	int y;
	int	height;
}					t_point;

typedef	struct		s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}					t_window;

void			print_line(t_point a, t_point b, t_window ptr);
int				**build_tab(char *name, t_point *size);
int				get_next_line(const int fd, char **line);
int				**alloc_tab(char *name, t_point *size);
t_point			**convert_tab(int **tab, t_point size);
void			print_matrix(t_window ptr, t_point **matrix, t_point size);

#endif
