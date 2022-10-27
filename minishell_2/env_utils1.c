/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:34:37 by risolon           #+#    #+#             */
/*   Updated: 2022/10/27 19:18:35 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_envp(t_info *info)
{
	int		count;
	char	**new_env;
	t_list	*dup;
	int		i;

	count = ft_lstsize(info->vars);
	new_env = malloc(sizeof(char *) * (count + 1));
	if (!new_env)
		return (ft_error(info, 1));
	new_env[count] = NULL;
	dup = info->vars;
	i = 0;
	while (dup)
	{
		new_env[i++] = ft_strdup(dup->content);
		dup = dup->next;
	}
	if (info->env)
		ft_malloc_error(info->env);
	info->env = new_env;
	return (1);
}

void	get_env(t_info *info)
{
	t_list	*dup;

	dup = info->vars;
	while (dup)
	{
		ft_putstr_fd(dup->content, 1);
		ft_putchar_fd('\n', 1);
		dup = dup->next;
	}
	exit(0);
}

int	check_name_var_pars(char *str)
{
	if (!str)
		return (0);
	if (!ft_isalpha(*str))
		if (*str != '_')
			return (0);
	while (str && *str && *str != '=' && *str != '$'
		&& *str != 34 && *str != 39)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (0);
		str++;
	}
	return (1);
}

int	check_env_pars(char *s)
{
	int		len;
	char	*tmp;

	len = 0;
	while (s && s[len] != ' ' && s[len] != 34 && s[len] != '\0')
		len++;
	tmp = ft_substr(s, 0, len);
	if (!ft_strncmp(tmp, "$?", 2))
	{
		if (tmp)
			free(tmp);
		return (2);
	}
	if (check_name_var_pars(tmp + 1) == 0)
	{
		if (tmp)
			free(tmp);
		return (1);
	}
	if (tmp)
		free(tmp);
	return (0);
}

int	ft_swap_ask(t_info *info, int index, int i)
{
	char	*digit;

	digit = ft_itoa(1);
	if (!digit)
		return (ft_error(info, 1));
	info->splited[index] = \
		ft_import(info->splited[index], digit, i, ft_strlen(digit) + 1);
	return (ft_strlen(digit) - 1);
}
