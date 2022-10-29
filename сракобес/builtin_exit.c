/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:23:19 by ccamembe          #+#    #+#             */
/*   Updated: 2022/10/29 17:39:23 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strisdig(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i++]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(s, 2);
			ft_putstr_fd(": numeric argument required", 2);
			ft_putchar_fd('\n', 2);
			return (0);
		}
	}
	return (1);
}

void	ft_exit(char *argv, t_info *info)
{
	char	**splited;

	splited = ft_split_wquots(argv);
	if (splited[1] && splited[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments", 2);
		ft_putchar_fd('\n', 2);
		exit(ft_atoi(splited[1]));
	}
	if (splited[1] && !ft_strisdig(splited[1]))
		info->exit = 255;
	else if (splited[1])
		info->exit = ft_atoi(splited[1]);
	else
		info->exit = 1;
	ft_malloc_error(splited);
	exit(info->exit);
}
