/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:57:05 by risolon           #+#    #+#             */
/*   Updated: 2021/10/13 18:30:04 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(buf1 + i) != *(unsigned char *)(buf2 + i))
			return (*(unsigned char *)(buf1 + i) - *(unsigned char *)
			(buf2 + i));
		i++;
	}
	return (0);
}
