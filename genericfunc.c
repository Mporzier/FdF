/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genericfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:38:05 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/10 14:37:36 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void		ft_lstxsuppr(t_list **begin)
{
	t_list	*stb;
	t_list	*nxt;

	stb = *begin;
	while (stb)
	{
		nxt = stb->next;
		free(stb);
		stb = nxt;
	}
	*begin = NULL;
}

void		ft_lstsuppr(t_list_y **begin)
{
	t_list_y	*stb;
	t_list_y	*cc;

	stb = *begin;
	while (stb)
	{
		ft_lstxsuppr(&stb->lst);
		free(stb->lst);
		cc = stb->next;
		free(stb);
		stb = cc;
	}
	*begin = NULL;
}

void		erase_number(char **str)
{
	int i;

	i = 0;
	while ((*str)[i] == ' ')
		i++;
	while ((*str)[i])
	{
		if ((*str)[i] == ' ')
			break ;
		(*str)[i] = ' ';
		i++;
	}
}

int			check_isempty(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
