/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:53:55 by risolon           #+#    #+#             */
/*   Updated: 2021/10/14 18:38:26 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*root;
	t_list	*tmp;

	if (lst != NULL && f != NULL)
	{
		root = ft_lstnew(f(lst->content));
		tmp = root;
		while (lst->next)
		{
			lst = lst->next;
			tmp->next = ft_lstnew(ft_strdup(f(lst->content)));
			if ((tmp->next) == NULL)
			{
				ft_lstclear(&root, del);
				return (NULL);
			}
			tmp = tmp->next;
		}
		return (root);
	}
	return (NULL);
}
