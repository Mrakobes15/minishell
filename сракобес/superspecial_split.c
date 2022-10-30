/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superspecial_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:47:14 by risolon           #+#    #+#             */
/*   Updated: 2022/10/29 17:47:14 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_interval_len(char *args, int *i)
{
	int	len;

	len = 0;
	if (is_it_quot(args[*i], 0) != 0)
	{
		(*i)++;
		while (is_it_quot(args[*i], 0) && args[*i])
		{
			(*i)++;
			len++;
		}
	}
	else
	{
		while (args[*i] && args[*i] != 34 && args[*i] != 39 && args[*i] != ' ')
		{
			(*i)++;
			len++;
		}
	}
	return (len);
}

void	make_strings(int acc, char *args, char **splited)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	is_it_quot(' ', 1);
	while (j < acc)
	{
		len = 0;
		while (args[i] && args[i] == ' ')
			i++;
		len = get_interval_len(args, &i);
		splited[j++] = ft_substr(args, i - len, len);
	}
}

size_t	ft_word_count_up2(char *s, char *c, int code)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	is_it_quot(s[i], 1);
	count = ft_parser_split_helper2(s, i, c, code);
	return (count);
}

char	**ft_split_wquots(char *args)
{
	char	**splited;
	int		acc;

	acc = ft_word_count_up2(args, "  ", 0);
	splited = malloc(sizeof(char *) * (acc + 1));
	if (!splited)
		ft_error(NULL, 1);
	splited[acc] = NULL;
	is_it_quot(' ', 1);
	make_strings(acc, args, splited);
	return (splited);
}
