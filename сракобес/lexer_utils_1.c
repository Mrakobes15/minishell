/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamembe <ccamembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:33:25 by risolon           #+#    #+#             */
/*   Updated: 2022/10/28 18:02:05 by ccamembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_cmd(char *buff)
{
	printf("wtf ");
	int		buffer_len;
	char	*tmp;

	printf("msh> ");
	get_next_line(0, &buff);
	buffer_len = ft_strlen(buff);
	while (buffer_len > 1 && buff[buffer_len - 1] == '\\')
	{
		buff[buffer_len - 1] = '\n';
		buff[buffer_len] = '\0';
		printf("msh> ");
		tmp = buff;
		get_next_line(0, &buff);
		buff = ft_strjoin(tmp, buff);
		buffer_len = ft_strlen(buff);
	}
	return (buff);
}

int	ft_quot(char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == 34 && (flag == 0 || flag == 1))
		{
			if (flag == 0)
				flag = 1;
			else if (flag == 1)
				flag = 0;
		}
		if (s[i] == 39 && (flag == 0 || flag == 2))
		{
			if (flag == 0)
				flag = 2;
			else if (flag == 2)
				flag = 0;
		}
		i++;
	}
	return (flag);
}

int	is_it_quot(char s, int code)
{
	static int	flag = 0;

	if (code == 1)
	{
		flag = 0;
		return (flag);
	}
	if (code == 2)
	{
		return (flag);
	}
	if (s == 34 && flag == 0)
		flag = 1;
	else if (s == 34 && flag == 1)
		flag = 0;
	else if (s == 39 && flag == 0)
		flag = 2;
	else if (s == 39 && flag == 2)
		flag = 0;
	return (flag);
}

int	check_semicolon(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		is_it_quot(str[i][j], 1);
		while (str[i][j])
		{
			if (is_it_quot(str[i][j], 0) == 0 && str[i][j] == ';')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_space_in_quot(t_info *info)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	is_it_quot(info->line[i], 1);
	while (info->line[i] == ' ')
		i++;
	while (info->line[i])
	{
		flag = is_it_quot(info->line[i], 0);
		if (flag != 0 && info->line[i] == ' ')
			return (1);
		else if (flag == 0 && info->line[i] == ' ')
			return (0);
		i++;
	}
	return (0);
}
