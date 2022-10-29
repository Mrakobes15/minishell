/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:41:06 by risolon           #+#    #+#             */
/*   Updated: 2021/10/13 18:10:11 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	arr = (char *)malloc(count * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, count * size);
	return (arr);
}
