/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:40:36 by risolon           #+#    #+#             */
/*   Updated: 2022/10/24 17:50:51 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_gnlstrjoin(char *remains, char *buffer)
{
	char	*omegalul;
	int		i;
	int		j;

	i = ft_strlen(remains) + ft_strlen(buffer);
	if (!remains && !buffer)
		return (NULL);
	omegalul = malloc(sizeof(char) * (i + 1));
	if (omegalul == NULL)
		ft_error(NULL, 1);
	i = 0;
	j = 0;
	if (remains)
	{
		while (remains[i])
			omegalul[j++] = remains[i++];
		i = 0;
	}
	while (buffer[i])
		omegalul[j++] = buffer[i++];
	omegalul[ft_strlen(remains) + ft_strlen(buffer)] = '\0';
	free(remains);
	return (omegalul);
}

int	ft_strrchr_deep(char *s, int c)
{
	size_t	i;
	char	*b;

	b = (char *)s;
	i = ft_strlen(s) + 1;
	is_it_quot(' ', 1);
	while (i--)
	{
		if ((is_it_quot(b[i], 0) == 0) && b[i] == (char) c)
		{
			return (i);
		}
	}
	return (0);
}

void	last_redir_helper(t_info *info, char *s, int index)
{
	int	j;

	j = -1;
	j = ft_strrchr_deep(s, '<');
	if (j != 0)
	{
		if (s[j - 1] == '<')
			info->last_r[index] = 2;
		else
			info->last_r[index] = 1;
	}
	else
		info->last_r[index] = 1;
}

void	last_redir(t_info *info, char **s)
{
	int	iinc[3];

	iinc[0] = 0;
	iinc[2] = 0;
	while (s[iinc[0]])
	{
		iinc[2]++;
		iinc[0]++;
	}
	iinc[0] = 0;
	iinc[1] = 0;
	info->last_r = malloc((sizeof(int) + 1) * iinc[2] / 2);
	if (info->last_r == NULL)
		ft_error(info, 1);
	while (s[iinc[0]])
	{
		while (s[iinc[0]] && (s[iinc[0]][0] == ';' || s[iinc[0]][0] == '|'))
			iinc[0]++;
		if (!s[iinc[0]])
			break ;
		last_redir_helper(info, s[iinc[0]], iinc[1]);
		iinc[0]++;
		iinc[1]++;
	}
}
