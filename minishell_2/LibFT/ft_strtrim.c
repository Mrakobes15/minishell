/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:48:06 by risolon           #+#    #+#             */
/*   Updated: 2021/10/09 18:05:59 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_seek(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		beg;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	beg = 0;
	end = ft_strlen(s1);
	while (s1[beg] && ft_seek(s1[beg], set))
		beg++;
	while (end > beg && ft_seek(s1[end - 1], set))
		end--;
	res = malloc(sizeof(*res) * (end - beg + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[beg] && beg < end)
		res[i++] = s1[beg++];
	res[i] = '\0';
	return (res);
}
