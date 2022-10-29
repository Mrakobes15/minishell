/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:14:07 by risolon           #+#    #+#             */
/*   Updated: 2021/10/08 21:19:35 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = (char *)dest;
	while (i < n)
	{
		*dst = (char)c;
		i++;
		dst++;
	}
	return (dest);
}
