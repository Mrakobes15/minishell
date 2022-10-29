/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:36:13 by risolon           #+#    #+#             */
/*   Updated: 2021/10/13 17:55:55 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp_dest;
	const char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dest = (char *)dest;
	tmp_src = (const char *)src;
	while (n)
	{
		*tmp_dest++ = *tmp_src++;
		n--;
	}
	return (dest);
}
