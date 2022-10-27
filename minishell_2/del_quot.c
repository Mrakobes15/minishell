/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_quot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:43:04 by risolon           #+#    #+#             */
/*   Updated: 2022/10/20 18:06:53 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_delquot(char *s, char *nl)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == 34)
		{
			j++;
			while (s[j] != 34 && s[j])
				nl[i++] = s[j++];
		}
		else if (s[j] == 39)
		{
			j++;
			while (s[j] != 39 && s[j])
				nl[i++] = s[j++];
		}
		if (s[j] == 34 || s[j] == 39)
			j++;
		nl[i++] = s[j++];
	}
	nl[i] = '\0';
}

void	ft_swap_string(t_info *info, int pos, char *src)
{
	int		i;
	char	*tmp;
	char	*tmp1;

	i = 0;
	while (info->splited[pos][i] == ' ' && info->splited[pos][i])
		i++;
	while (info->splited[pos][i] == ' ' && info->splited[pos][i])
		i++;
	tmp = ft_substr(info->splited[pos], i, (ft_strlen(info->splited[pos] - i)));
	tmp1 = ft_strjoin(src, tmp);
	if (info->splited[pos])
		free(info->splited[pos]);
	if (tmp)
		free(tmp);
	if (src)
		free(src);
	info->splited[pos] = tmp1;
}

void	change_f_command(t_info *info)
{
	int		i;
	char	**tmp;
	char	*tmp1;
	char	*nl;

	i = 0;
	while (info->splited[i])
	{
		tmp = ft_split(info->splited[i], ' ');
		if (ft_quot(tmp[0]) == 0)
		{
			if (ft_strchr(tmp[0], 34) || ft_strchr(tmp[0], 39))
			{
				nl = malloc(sizeof(char) * (ft_strlen(tmp[0] - 1)));
				if (!nl)
					ft_error(info, 1);
				ft_delquot(tmp[0], nl);
				tmp1 = nl;
				ft_swap_string(info, i, tmp1);
			}
		}
		ft_malloc_error(tmp);
		i++;
	}
}
