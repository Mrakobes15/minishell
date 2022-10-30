/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:18:56 by risolon           #+#    #+#             */
/*   Updated: 2022/10/30 16:59:34 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_create_node(t_info *info, int *j)
{
	int		i;
	int		tmp;
	int		len;
	char	**nl;

	i = (*j);
	len = 0;
	while (info->commands[i] && info->commands[i][0] != '|')
	{
		i++;
		len++;
	}
	tmp = (*j);
	(*j) = i + 1;
	nl = ft_calloc(len + 1, sizeof(char *));
	if (nl == NULL)
		ft_error(NULL, 1);
	i = 0;
	while (i + tmp < tmp + len)
	{
		nl[i] = ft_strdup(info->commands[tmp + i]);
		i++;
	}
	nl[i] = NULL;
	return (nl);
}

char	***create_cmd(t_info *info)
{
	char	***cmd;
	int		i;
	int		len;
	int		order;

	i = 0;
	order = 0;
	cmd = NULL;
	len = command_count(info->commands);
	if (len != 0)
	{
		cmd = ft_calloc(len + 1, sizeof(char **));
		if (cmd == NULL)
			ft_error(NULL, 1);
		while (i < len)
		{
			cmd[i] = ft_create_node(info, &order);
			i++;
		}
		cmd[i] = NULL;
	}
	return (cmd);
}
