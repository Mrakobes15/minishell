/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:40:36 by risolon           #+#    #+#             */
/*   Updated: 2022/10/27 18:51:59 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	enver(t_info *info, int index, int i, int j)
{
	char	*nl;
	int		c;

	c = 0;
	nl = malloc(sizeof(char) * (ft_strlen(info->splited[index]) - j + 1));
	if (!nl)
		ft_error(info, 1);
	while (c < i)
	{
		nl[c] = info->splited[index][c];
		c++;
	}
	i += j;
	while (info->splited[index][i])
		nl[c++] = info->splited[index][i++];
	nl[c] = '\0';
	if (info->splited[index])
		free(info->splited[index]);
	info->splited[index] = nl;
	return (-1);
}

char	*ft_import(char	*str1, char *str2, int i, int j)
{
	char	*nl;
	int		zh[2];

	zh[0] = 0;
	nl = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) - j + 1));
	if (!nl)
		ft_error(NULL, 1);
	while (zh[0] < i)
	{
		nl[zh[0]] = str1[zh[0]];
		zh[0]++;
	}
	zh[1] = 0;
	while (str2[zh[1]])
		nl[zh[0]++] = str2[zh[1]++];
	i += j;
	while (str1[i])
		nl[zh[0]++] = str1[i++];
	nl[zh[0]] = '\0';
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (nl);
}

int	ft_swap_env(t_info *info, int index, int i)
{
	char	*name;
	int		j;
	int		tmp;
	char	*str;

	tmp = i + 1;
	if (check_env_pars(&info->splited[index][i]) == 2)
		return (ft_swap_ask(info, index, i));
	else if (ft_isdigit(info->splited[index][tmp]))
		return (enver(info, index, i, 2));
	else if (check_env_pars(&info->splited[index][i]))
		return (0);
	while (ft_isalnum(info->splited[index][tmp]) && info->splited[index][tmp])
		tmp++;
	j = 1 + (tmp - (i + 1));
	name = ft_substr(info->splited[index], i, j);
	name[ft_strlen(name) + 1] = '\0';
	name[ft_strlen(name)] = '=';
	str = find_env(name + 1, info);
	if (name != NULL)
		free(name);
	if (str == NULL)
		return (enver(info, index, i, j));
	info->splited[index] = ft_import(info->splited[index], str, i, j);
	return (ft_strlen(str) - 1);
}
