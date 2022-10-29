/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamembe <ccamembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:59:34 by risolon           #+#    #+#             */
/*   Updated: 2022/10/28 17:49:20 by ccamembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

void	ft_mshfree_helper(int exc, t_info *info)
{
	if (exc == 2)
		g_error = 258;
	if (info->last_r)
	{
		free(info->last_r);
		info->last_r = NULL;
		info->pip.curr_index = 0;
	}
}

int	ft_mshfree1(t_info *info, int code, int exc)
{
	int	i;

	if (code == 1)
	{
		if (info->line)
			free(info->line);
	}
	else if (code == 2)
	{
		if (info->line)
			free(info->line);
		i = 0;
		while (info->cmd[i])
		{
			ft_malloc_error(info->cmd[i]);
			i++;
		}
		if (info->cmd)
			free(info->cmd);
	}
	ft_mshfree_helper(exc, info);
	return (1);
}

char	*add_semicolon(void)
{
	char	*string;

	string = malloc(sizeof(char) * 2);
	if (!string)
		ft_error(NULL, 1);
	string[0] = ';';
	string[1] = '\0';
	return (string);
}

int	add_pipe_helper(t_info	*info, char **newcom, int i, int j)
{
	while (info->splited[i])
	{
		newcom[j++] = add_semicolon();
		newcom[j++] = info->splited[i];
		newcom[j++] = add_semicolon();
		if (info->splited[i + 1] != NULL)
		{
			newcom[j] = malloc(sizeof(char) * 2);
			if (newcom[j] == NULL)
				return (ft_error(info, 1));
			newcom[j][0] = '|';
			newcom[j][1] = '\0';
			j++;
		}
		i++;
	}
	newcom[j] = NULL;
	return (0);
}

int	add_pipe(t_info *info)
{
	char	**newcom;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	while (info->splited[i])
		i++;
	len = (i + i - 1) + i * 2;
	newcom = malloc(sizeof(char *) * (len + 1));
	if (newcom == NULL)
		return (ft_error(info, 1));
	len = i;
	i = 0;
	j = 0;
	add_pipe_helper(info, newcom, i, j);
	if (info->commands)
		ft_malloc_error(info->commands);
	info->commands = newcom;
	return (1);
}
