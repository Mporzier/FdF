/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:46:18 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/08 14:11:49 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ptr[n] = '\0';
	while (i < n)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}
