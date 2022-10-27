/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:00:57 by risolon           #+#    #+#             */
/*   Updated: 2021/10/13 18:17:49 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*st;
	int			i;

	st = str;
	i = 0;
	while (str[i + 1])
	{
		i++;
		st++;
	}
	if (c == '\0')
	{
		st += 1;
		return ((char *)st);
	}
	while (str[i] && i >= 0)
	{
		if (str[i] == c)
			return ((char *)st);
		st--;
		i--;
	}
	return ((void *)0);
}
