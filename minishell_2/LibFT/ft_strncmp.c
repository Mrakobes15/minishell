/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:19:13 by risolon           #+#    #+#             */
/*   Updated: 2021/10/13 18:43:09 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	cmp(char c, char c1)
{
	if ((unsigned char)c != (unsigned char)c1)
		return ((unsigned char)c - (unsigned char)c1);
	return (0);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str1[i] && str2[i])
	{
		if (cmp(str1[i], str2[i]))
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if (i < n)
		return (cmp(str1[i], str2[i]));
	return (0);
}
