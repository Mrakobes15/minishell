/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:23:28 by ccamembe          #+#    #+#             */
/*   Updated: 2022/10/29 17:41:36 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_name_var(char *s)
{
	if (!s)
		return (0);
	if (!ft_isalpha(*s))
		if (*s != '_')
			return (0);
	while (s && *s && *s != '=')
	{
		if (!ft_isalnum(*s) && *s != '_')
			return (0);
		s++;
	}
	return (1);
}

int	ft_delelem(t_list **contents)
{
	t_list	*current;
	t_list	*next;

	current = *contents;
	next = (*contents)->next;
	current->next = next->next;
	ft_lstdelone(next, free);
	return (0);
}

int	ft_unset_print_err(char **splited, int i)
{
	if (!check_name_var(splited[i]))
	{
		ft_putstr_fd("unset: ", 2);
		ft_putstr_fd("`", 2);
		ft_putstr_fd(splited[i], 2);
		ft_putstr_fd("': ", 2);
		ft_putstr_fd("not a valid identifier\n", 2);
		ft_malloc_error(splited);
		return (0);
	}
	return (1);
}

void	ft_unset_helper(char *splited_i, int len, t_info *info)
{
	t_list	*dup;
	char	*tmp;

	dup = info->vars;
	tmp = ft_strjoin(splited_i, "=");
	while (dup->next)
	{
		if (!ft_strncmp(dup->next->content, tmp, len + 1))
		{
			ft_delelem(&(dup));
			break ;
		}
		dup = dup->next;
	}
	free(tmp);
}

int	ft_unset(char *var, t_info *info)
{
	char	**splited;
	int		i;
	int		len;

	splited = ft_split_wquots(var);
	i = 1;
	len = ft_strlen(splited[i]);
	while (splited[i])
	{
		if (!ft_unset_print_err(splited, i))
			return (1);
		ft_unset_helper(splited[i], len, info);
		i++;
		len = ft_strlen(splited[i]);
	}
	set_envp(info);
	ft_malloc_error(splited);
	return (0);
}
