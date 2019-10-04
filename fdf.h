/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:41:13 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/15 19:36:24 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define OX 2000
# define OY 600
# define SIZE_X 8000
# define SIZE_Y 8000

typedef	struct		s_point
{
	short			x;
	short			y;
	short			h;
}					t_point;

typedef struct		s_list
{
	t_point			pt;
	struct s_list	*next;
}					t_list;

typedef struct		s_list_y
{
	t_list			*lst;
	struct s_list_y	*next;
}					t_list_y;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef	struct		s_env
{
	t_point			sz;
	t_pos			o;
	t_point			sc;
	void			*mlx;
	void			*win;
	void			*i_p;
	unsigned char	*i_s;
	t_list_y		*begin;
	char			*name;
	int				status;
}					t_env;

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_points
{
	t_point			a;
	t_point			b;
	t_env			ptr;
}					t_points;

int					get_next_line(const int fd, char **line);
void				ft_lstsuppr(t_list_y **begin);
int					ft_atoi(const char *str);
int					checkerrors(char *name, t_env *mlx);
t_list_y			*create_list(char *name, t_env *ptr);
t_list_y			*create_list2(char *name, t_env *ptr);
int					error_msg(int status);
void				fill_pixel(unsigned char *i_s, int x, int y, t_color col);
void				print_line(t_point i, t_point f, t_env ptr);
void				print_list(t_env *ptr);
void				erase_number(char **line);
int					check_isempty(char *str);
int					ft_abs(int i);
int					key_events(int key, t_env *ptr);
t_color				calc_color(t_points m);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
