/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:03:14 by risolon           #+#    #+#             */
/*   Updated: 2021/10/09 16:23:30 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*tmp_dest;
	const char	*tmp_src;

	if (dest < src)
	{
		tmp_dest = (char *)dest;
		tmp_src = (const char *)src;
		while (len)
		{
			*tmp_dest++ = *tmp_src++;
			len--;
		}
	}
	else if (dest > src)
	{
		tmp_dest = (char *)dest + len - 1;
		tmp_src = (const char *)src + len - 1;
		while (len)
		{
			*tmp_dest-- = *tmp_src--;
			len--;
		}
	}
	return (dest);
}
