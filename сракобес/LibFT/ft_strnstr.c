/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:41:21 by risolon           #+#    #+#             */
/*   Updated: 2021/10/08 20:03:10 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*str2))
		return ((char *)str1);
	while (i < n && str1[i])
	{
		j = 0;
		while (str1[i + j] == str2[j] && i + j < n)
		{
			if (!str2[j + 1])
				return ((char *)str1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
