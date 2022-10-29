/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:34:13 by risolon           #+#    #+#             */
/*   Updated: 2022/10/24 16:13:04 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	helper(char *str, int *i)
{
	int	j;

	j = 0;
	while (str[*i] == ' ' && str[*i])
	{
		j++;
		(*i)++;
	}
	return (j);
}

void	skip_quot(char *str, int *i, int *j)
{
	if (str[*i] == 34)
	{
		while (str[*i] != 34 && str[*i])
		{
			(*j)++;
			(*i)++;
		}
	}
	else if (str[*i] == 39)
	{
		while (str[*i] != 39 && str[*i])
		{
			(*j)++;
			(*i)++;
		}
	}
	else if ((ft_isalnum(str[*i]) || str[*i] == '.'))
	{
		while ((ft_isalnum(str[*i]) || str[*i] == '.') && str[*i])
		{
			(*j)++;
			(*i)++;
		}
	}
}

char	*skip_semic(char	*str)
{
	char	*tmp;

	tmp = ft_substr(str, 1, ft_strlen(str));
	if (str != NULL)
		free(str);
	return (tmp);
}

char	*rebuilder(t_info *info, int i, int len, int index)
{
	char	*nl;
	char	*modif;
	char	*tmp;
	char	*tmp1;

	modif = ft_substr(info->commands[index], 0, i);
	nl = ft_substr(info->commands[index], i, len);
	tmp = modif;
	tmp1 = ft_substr(info->commands[index], i + len, \
		(ft_strlen(info->commands[index]) - len - i));
	modif = ft_strjoin(modif, tmp1);
	if (info->commands[index] != NULL)
		free(info->commands[index]);
	info->commands[index] = modif;
	if (tmp)
		free(tmp);
	if (tmp1)
		free(tmp1);
	return (nl);
}

int	find_name_len(char *str, int i, char c)
{
	int	j;

	j = 0;
	while (str[i] == c)
	{
		i++;
		j++;
	}
	j += helper(str, &i);
	skip_quot(str, &i, &j);
	return (j);
}
