/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:57:59 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/15 19:38:59 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error_msg(int status)
{
	if (status == 0)
		write(1, "error\n", 6);
	if (status == 1)
		write(1, "usage: ./fdf source_file\n", 25);
	return (0);
}

int		check_empty_file(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			return (0);
		i++;
	}
	return (1);
}

int		count_numbers(char *str)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '-')
			return (-1);
		i++;
	}
	i = 0;
	while (*str != '\0')
	{
		if (*str == ' ' && i == 1)
			i = 0;
		if (*str != ' ' && i == 0)
		{
			i = 1;
			k++;
		}
		str++;
	}
	return (k);
}

int		ft_finish(int fd, char **line, int i, t_env *mlx)
{
	close(fd);
	free(*line);
	if (mlx != NULL)
	{
		mlx->sz.x = i;
		return (0);
	}
	return (1);
}

int		checkerrors(char *name, t_env *mlx)
{
	int		fd;
	char	*line;
	int		i;
	int		k;
	int		s;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (1);
	k = 0;
	mlx->sz.y = 0;
	while ((s = get_next_line(fd, &line)) > 0)
	{
		i = count_numbers(line);
		if (i == -1)
			return (ft_finish(fd, &line, i, NULL));
		if (k == 0)
			k = i;
		if (k != i)
			return (ft_finish(fd, &line, i, NULL));
		mlx->sz.y++;
		free(line);
	}
	if (s == -1 || (check_empty_file(line) == 1 && k == 0))
		return (1);
	return (ft_finish(fd, &line, i, mlx));
}
