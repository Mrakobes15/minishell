/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamembe <ccamembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:47:04 by risolon           #+#    #+#             */
/*   Updated: 2022/10/28 17:18:03 by ccamembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_dollar(t_info *info)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (info->splited[i])
	{
		j = 0;
		flag = is_it_quot(info->splited[i][j], 1);
		while (info->splited[i][j])
		{
			flag = is_it_quot(info->splited[i][j], 0);
			if (info->splited[i][j] == '$')
			{
				if (flag == 2)
					while (ft_isalnum(info->splited[i][j])
					&& info->splited[i][j])
							j++;
				else
						j += ft_swap_env(info, i, j);
			}
			j++;
		}
		i++;
	}
}

int	redir_error(char *str, int i)
{
	int	j;

	is_it_quot(' ', 1);
	while (str[i + 1] == ' ' && str[i + 1])
		i++;
	j = i + 1;
	if (str[i + 1] == '>' || str[i + 1] == '|'
		|| str[i + 1] == '<' || !str[i + 1])
		return (0);
	if (ft_isdigit(str[j]) && str[j - 1] == '>' && str[j + 1] == '>')
		return (0);
	return (1);
}

int	check_redir(t_info *info)
{
	int	i;
	int	tmp;

	i = 0;
	while (info->line[i])
	{
		tmp = check_redir_helper(info->line[i], i);
		if ((info->line[i] == '>' || info->line[i] == '<') && tmp == 0)
		{
			if ((info->line[i + 1] == '>' && info->line[i] == '>')
				|| (info->line[i + 1] == '<' && info->line[i] == '<'))
			{
				if (redir_error(info->line, i + 1) == 0 && tmp == 0)
					return (1);
				i++;
			}
			else
			{
				if (redir_error(info->line, i) == 0 && tmp == 0)
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int	check_pipes(t_info *info)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	is_it_quot(info->line[i], 1);
	while (info->line[i])
	{
		j = i;
		if (is_it_quot(info->line[i], 0) == 0 && info->line[i] == '|')
		{
			flag = 0;
			while (info->line[j + 1] != '|' && info->line[j + 1])
			{
				if (info->line[j + 1] != ' ')
					flag = 1;
				j++;
			}
			if (flag == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_cutter(t_info *info)
{
	int		i;
	char	*tmp;

	i = 0;
	while (info->commands[i])
	{
		tmp = ft_strtrim(info->commands[i], " ");
		if (info->commands[i])
			free(info->commands[i]);
		info->commands[i] = tmp;
		i++;
	}
}
