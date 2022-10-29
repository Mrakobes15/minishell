/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:39:31 by risolon           #+#    #+#             */
/*   Updated: 2022/10/29 18:40:03 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strrchr_upred(char *str, int c)
{
	size_t	i;
	char	*b;

	b = (char *)str;
	i = ft_strlen(str) + 1;
	is_it_quot(' ', 1);
	while (i--)
	{
		if ((is_it_quot(b[i], 0) == 0) && b[i] == (char) c)
		{
			return (1);
		}
	}
	return (0);
}

void	create_left(t_info *info, char *str, int index)
{
	int		i;
	int		len;
	char	*buf;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == '<')
		{
			len = find_name_len(str, i, '<');
			buf = rebuilder(info, i, len, index);
			info->commands[index - 1] = \
				ft_gnlstrjoin(info->commands[index - 1], buf);
			if (buf != NULL)
				free(buf);
			if (info->commands[index - 1][0] == ';')
				info->commands[index - 1] = \
					skip_semic(info->commands[index - 1]);
			break ;
		}
		i--;
	}
}

void	create_double_left(t_info *info, char *str, int index)
{
	int		i;
	int		len;
	char	*buf;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] == '<')
		{
			len = find_name_len(str, i, '<');
			buf = rebuilder(info, i, len, index);
			info->commands[index - 1] = \
				ft_gnlstrjoin(info->commands[index - 1], buf);
			if (buf != NULL)
				free(buf);
			if (info->commands[index - 1][0] == ';')
				info->commands[index - 1] = \
					skip_semic(info->commands[index - 1]);
			break ;
		}
		i++;
	}
}

void	create_right(t_info	*info, char	*str, int in)
{
	int		i;
	int		j;
	int		len;
	char	*buf;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '>')
		{
			len = find_name_len(str, i, '>');
			buf = rebuilder(info, i, len, in);
			if (info->commands[in + 1])
				free(info->commands[in + 1]);
			info->commands[in + 1] = buf;
			while ((info->commands[in + 1][j] == '>'
				|| info->commands[in + 1][j] == ' ')
				&& info->commands[in + 1][j])
				j++;
			open_file_h(info->commands[in + 1], &info->commands[in + 1][j], 0);
			break ;
		}
		i++;
	}
}

void	rebuild_redir(t_info *info)
{
	int	i;

	i = 1;
	while (info->commands[i])
	{
		if (info->commands[i][0] == ';')
		{
			while (ft_strnstr(info->commands[i], "<<", \
				ft_strlen(info->commands[i])))
				create_double_left(info, info->commands[i], i);
			while (ft_strrchr_upred(info->commands[i], '<'))
				create_left(info, info->commands[i], i);
			while (ft_strrchr_upred(info->commands[i], '>'))
				create_right(info, info->commands[i], i);
		}
		if (info->commands[i + 1] && info->commands[i + 2])
			i += 2;
		if (info->commands[i + 1] != NULL)
			i++;
		if (info->commands[i + 1] != NULL)
			i++;
		else
			break ;
	}
}
