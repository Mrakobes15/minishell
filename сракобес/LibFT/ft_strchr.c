/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:16:05 by risolon           #+#    #+#             */
/*   Updated: 2021/10/13 18:11:52 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char	*st;
	int			i;

	st = str;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)st);
		st++;
		i++;
	}
	if (c == '\0')
		return ((char *)st);
	return ((void *)0);
}
