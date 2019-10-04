/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:29:53 by mporzier          #+#    #+#             */
/*   Updated: 2018/12/08 14:12:15 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(ptr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr[len] = '\0';
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	return (ptr);
}
