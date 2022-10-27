/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:34:56 by risolon           #+#    #+#             */
/*   Updated: 2022/10/24 18:06:42 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**modified_arg(char **argv)
{
	int		n;
	int		acc;
	char	**modif_arg;

	n = -1;
	acc = 0;
	while (argv[++n])
		if (ft_strncmp(argv[n], ";", 1) && argv[n][0] != '\0')
			acc++;
	modif_arg = ft_calloc(acc + 1, sizeof(char *));
	if (modif_arg == NULL)
		ft_error(NULL, 1);
	modif_arg[acc] = NULL;
	n = -1;
	acc = 0;
	while (argv[++n])
		if (ft_strncmp(argv[n], ";", 1) && argv[n][0] != '\0')
			modif_arg[acc++] = ft_strdup(argv[n]);
	if (argv)
		ft_malloc_error(argv);
	return (modif_arg);
}

char	**ft_add_string(char **arr, char *str)
{
	int		n;
	char	**result;

	n = 0;
	while (arr && arr[n])
		n++;
	result = ft_calloc(n + 1 + (str != NULL), sizeof(char *));
	if (!result)
		ft_error(NULL, 1);
	result[n + (str != NULL)] = NULL;
	n = 0;
	while (arr && arr[n])
	{
		result[n] = ft_strdup(arr[n]);
		n++;
	}
	result[n] = ft_strdup(str);
	if (arr)
		ft_malloc_error(arr);
	if (str)
		free(str);
	return (result);
}

void	foo_helper(char *s, int *c, int *len)
{
	while (s[(*c)] && (s[(*c)] == '<' || s[(*c)] == ' '))
	{
		(*c)++;
		(*len)++;
	}
	while (s[(*c)] && s[(*c)] != '<' && s[(*c)] != ' ')
	{
		(*c)++;
		(*len)++;
	}
}

char	**foo_bar(char **arr)
{
	char	**res;
	int		n;
	int		c;
	int		len;

	n = 0;
	res = NULL;
	while (arr[n])
	{
		if (ft_strncmp(arr[n], "<", 1))
			res = ft_add_string(res, ft_strdup(arr[n]));
		else
		{
			c = 0;
			while (arr[n][c] == '<')
			{
				len = 0;
				foo_helper(arr[n], &c, &len);
				res = ft_add_string(res, ft_substr(&arr[n][c - len], 0, len));
			}
		}
		n++;
	}
	ft_malloc_error(arr);
	return (res);
}

int		command_count(char **s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s && s[i])
		count = 1;
	while (s && s[i])
	{
		if (s[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}
