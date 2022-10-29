/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:09:00 by risolon           #+#    #+#             */
/*   Updated: 2022/10/22 17:17:26 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parser_split_helper(char *s, int i, char *c, int code)
{
	int	count;

	count = 0;
	while (s[i])
	{
		if ((s[i] != c[0] && s[i] != c[1]) && s[i])
		{
			count++;
			while ((is_it_quot(s[i], 0)
					|| (s[i] != c[0] && s[i] != c[1])) && s[i])
			{
				if (is_it_quot(s[i], 2) == 0 && s[i] == '|' && code == 1)
				{
					if (s[i - 1] != ' ')
						count ++;
					i++;
					break ;
				}
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

int	ft_parser_split_helper2(char *s, int i, char *c, int code)
{
	int	count;

	count = 0;
	while (s[i])
	{
		if (s[i] && (s[i] != c[0] && s[i] != c[1]))
		{
			if (s[i] != 34 && s[i] != 39 && code != 3)
				count++;
			while (s[i] && (s[i] != c[0] && s[i]))
			{
				if (s[i] == 34 || s[i] == 39)
				{
					count++;
					while (s[i] && is_it_quot(s[i], 0) != 0)
						i++;
					break ;
				}
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

size_t	ft_word_count_up(char *s, char *c, int code)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	is_it_quot(s[i], 1);
	count = ft_parser_split_helper(s, i, c, code);
	return (count);
}

char	*ft_newword_up(char *s, char c, size_t *i)
{
	char	*arr;
	size_t	len;
	size_t	start;

	len = 0;
	is_it_quot(' ', 1);
	while (s[*i] == c && s[*i])
	{
		(*i)++;
	}
	start = *i;
	while ((is_it_quot(s[*i], 0) || s[*i] != c) && s[*i])
	{
		len++;
		(*i)++;
	}
	arr = ft_calloc(len + 1, sizeof(char));
	ft_strlcpy(arr, &s[start], len + 1);
	return (arr);
}

char	**ft_split_up(char *s, char *c)
{
	char	**string;
	size_t	word_count;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	word_count = ft_word_count_up(s, c, 1);
	string = ft_calloc(word_count + 1, sizeof(char *));
	if (string == NULL)
		ft_error(NULL, 1);
	while (i < word_count)
	{
		string[i] = ft_newword_up((char *)s, c[0], &j);
		if (string[i] == NULL)
		{
			return (ft_malloc_error(string));
		}
		i++;
	}
	string[i] = NULL;
	return (string);
}
