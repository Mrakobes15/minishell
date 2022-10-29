/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:42:48 by risolon           #+#    #+#             */
/*   Updated: 2022/10/20 17:51:11 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_w(char const *s, char c)
{
	int	words;
	int	i;

	if (!s)
		return (0);
	words = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i])
		{
			words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		words++;
	return (words);
}

static char	*ft_add(const char *str, char c)
{
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != 0)
		i++;
	copy = malloc(sizeof(*copy) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_malloc_error(char **res)
{
	unsigned int	i;

	i = 0;
	while (res && res[i])
	{
		if (res)
			free(res[i]);
		i++;
	}
	if (res)
		free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_count_w(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_count_w(s, c) && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		res[j] = ft_add(&s[i], c);
		if (!res[j])
			return (ft_malloc_error(res));
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	res[j] = NULL;
	return (res);
}
