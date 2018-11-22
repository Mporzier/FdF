/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:36:47 by mporzier          #+#    #+#             */
/*   Updated: 2018/11/21 09:31:44 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int				calc(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int				build_line(char **line, char **str, size_t *i)
{
	char *ptr;

	if (!(*line = ft_strndup(*str, calc(*str))))
		return (1);
	if (ft_strchr(*str, '\n') != NULL)
	{
		ptr = *str;
		if (!(*str = ft_strsub(*str, calc(*str) + 1, ft_strlen(*str))))
			return (1);
		free(ptr);
	}
	else
	{
		free(*str);
		if (!(*str = ft_strnew(0)))
			return (1);
	}
	*i = ft_strlen(*line);
	return (0);
}

int				read_stuff(char **string, int *ret, const int fd, char *buf)
{
	char *ptr;

	while (ft_strchr(*string, '\n') == NULL && *ret == BUFF_SIZE)
	{
		*ret = read(fd, buf, BUFF_SIZE);
		buf[*ret] = 0x00;
		if (!(ptr = ft_strjoin(*string, buf)))
			return (1);
		free(*string);
		*string = ptr;
	}
	free(buf);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*file[4864];
	char			*buf;
	int				ret;
	size_t			i;

	i = 0;
	ret = BUFF_SIZE;
	if (fd < 0 || BUFF_SIZE < 1 || fd > 4864 || !line
			|| (buf = ft_strnew(BUFF_SIZE + 1)) == NULL || read(fd, buf, 0) < 0
			|| (file[fd] == NULL && !(file[fd] = ft_strnew(0))))
		return (-1);
	if (read_stuff(&file[fd], &ret, fd, buf) == 1)
		return (-1);
	if (build_line(line, &file[fd], &i) == 1)
		return (-1);
	if (ret == 0 && i == 0)
		return (0);
	return (1);
}
