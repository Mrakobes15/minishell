/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:31:17 by risolon           #+#    #+#             */
/*   Updated: 2021/10/10 19:20:00 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_plus(int n, int size)
{
	char	*res;

	res = malloc(sizeof(*res) * (size + 1));
	if (res)
	{
		res[size] = '\0';
		while (size)
		{
			res[--size] = n % 10 + '0';
			n /= 10;
		}
		return (res);
	}
	return (NULL);
}

static char	*ft_minus(int n, int size)
{
	char	*res;

	res = malloc(sizeof(*res) * (size + 2));
	if (res)
	{
		res[size + 1] = '\0';
		res[0] = '-';
		while (size > 0)
		{
			res[size] = n % 10 + '0';
			n /= 10;
			size--;
		}
		return (res);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_len(n);
	if (n >= 0)
	{
		res = ft_plus(n, size);
		return (res);
	}
	if (n < 0)
	{
		res = ft_minus((-1 * n), size);
		return (res);
	}
	return (NULL);
}
