/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamembe <ccamembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:50:16 by risolon           #+#    #+#             */
/*   Updated: 2022/10/28 17:52:13 by ccamembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

char	*find_env(char *var, t_info *info)
{
	int		len;
	t_list	*dup;

	len = ft_strlen(var);
	dup = info->vars;
	while (dup)
	{
		if (!ft_strncmp(dup->content, var, len))
			break ;
		dup = dup->next;
	}
	if (!dup)
		return (NULL);
	return (ft_strdup(dup->content + len));
}

void	set_shlvl(t_info *info)
{
	char	*tmp;
	int		num;
	char	*digit;

	tmp = find_env("SHLVL=", info);
	num = ft_atoi(tmp) + 1;
	free(tmp);
	digit = ft_itoa(num);
	tmp = ft_strjoin("export SHLVL=", digit);
	free(digit);
	free(tmp);
}

void	init(t_info *info, int arg1, char **arg2, char **arg3)
{
	int	i;

	i = -1;
	info->line = NULL;
	info->commands = NULL;
	info->splited = NULL;
	info->promptflag = 1;
	info->argc = arg1;
	info->argv = arg2;
	info->env = NULL;
	info->exit = 0;
	g_error = 0;
	info->pip.lpipe[0] = -1;
	info->pip.lpipe[1] = -1;
	info->pip.rpipe[0] = -1;
	info->pip.rpipe[0] = -1;
	info->pip.in = -1;
	info->vars = NULL;
	info->last_r = NULL;
	info->pip.curr_index = 0;
	while (arg3[++i])
		if (ft_strncmp(arg3[i], "OLDPWD=", 7))
			ft_lstadd_back(&(info->vars), ft_lstnew(ft_strdup(arg3[i])));
	set_shlvl(info);
	rl_catch_signals = 0;
}

int	ft_space_check(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

int	check_redir_helper(char c, int i)
{
	if (i == 0)
		return (is_it_quot(' ', 1));
	else
		return (is_it_quot(c, 0));
}
