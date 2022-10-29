/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:23:11 by ccamembe          #+#    #+#             */
/*   Updated: 2022/10/29 18:53:51 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *arg, t_info *info)
{
	char	**splited;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	splited = ft_split_wquots(arg);
	if (!ft_strcmp(splited[i], "-n"))
	{
		i++;
		flag = 1;
	}
	while (splited[i])
	{	
		ft_putstr_fd(splited[i], 1);
		i++;
		if (splited[i])
			ft_putchar_fd(' ', 1);
	}
	if (!flag)
		ft_putchar_fd('\n', 1);
	(void)info;
	exit(0);
}
