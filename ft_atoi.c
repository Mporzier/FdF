/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:24:52 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/08 14:12:44 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_atoi(const char *str)
{
	int	i;
	int number;
	int minus;

	minus = 1;
	number = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ((str[i] <= '9' && str[i] >= '0') && str[i])
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * minus);
}
