/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:00:39 by risolon           #+#    #+#             */
/*   Updated: 2021/10/13 18:22:46 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	copy = malloc(sizeof(*copy) * (len + 1));
	if (!copy || !str)
		return (NULL);
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
