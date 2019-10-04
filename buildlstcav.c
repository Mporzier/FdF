/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildlstcav.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:31:01 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/10 17:43:57 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_list		*fill_link(t_list *ptr, t_point p, char **line, t_env *m)
{
	t_list			*n;
	static	t_list	*end = NULL;

	if (!(n = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	n->pt.h = ft_atoi(*line);
	n->pt.x = OX - p.y * m->sc.x + p.x * m->sc.x;
	n->pt.y = OY + p.x * m->sc.x - n->pt.h / 10 * m->sc.y;
	erase_number(line);
	n->next = NULL;
	if (ptr == NULL)
	{
		end = n;
		return (n);
	}
	else
	{
		end->next = n;
		end = end->next;
		return (ptr);
	}
}

static	t_list_y	*fill_list(t_list_y *n, int fd, int i, t_env *m)
{
	char	*line;
	t_point	p;

	p.y = i;
	p.x = 0;
	get_next_line(fd, &line);
	while (check_isempty(line) == 0)
	{
		n->lst = fill_link(n->lst, p, &line, m);
		p.x++;
	}
	free(line);
	return (n);
}

static	t_list_y	*create_list_y(t_list_y *beg, int fd, int i, t_env *m)
{
	static	t_list_y	*end = NULL;
	t_list_y			*n;

	if (!(n = (t_list_y*)malloc(sizeof(t_list_y))))
		return (NULL);
	n->lst = NULL;
	n->next = NULL;
	n = fill_list(n, fd, i, m);
	if (beg == NULL)
	{
		end = n;
		return (n);
	}
	else
	{
		end->next = n;
		end = end->next;
		return (beg);
	}
}

t_list_y			*create_list2(char *name, t_env *ptr)
{
	t_list_y		*beg;
	int				i;
	int				fd;

	fd = open(name, O_RDONLY);
	i = 0;
	beg = NULL;
	while (i < ptr->sz.y)
	{
		if (!(beg = create_list_y(beg, fd, i, ptr)))
		{
			ft_lstsuppr(&beg);
			close(fd);
			return (0);
		}
		i++;
	}
	close(fd);
	return (beg);
}
