/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:37:50 by risolon           #+#    #+#             */
/*   Updated: 2021/10/14 16:42:45 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	i++;
	return (i);
}
