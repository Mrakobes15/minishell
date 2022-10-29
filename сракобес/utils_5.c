/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:56:42 by risolon           #+#    #+#             */
/*   Updated: 2022/10/29 17:56:42 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd_minus_helper(char *prev_dir, t_info *info)
{
	char	*current_dir;
	char	*tmp;

	current_dir = find_env("PWD=", info);
	tmp = prev_dir;
	prev_dir = ft_strjoin("export OLDPWD=", current_dir);
	ft_export(prev_dir, info);
	free(prev_dir);
	free(current_dir);
	current_dir = ft_strjoin("export PWD=", tmp);
	free(tmp);
	ft_export(current_dir, info);
	free(current_dir);
	set_envp(info);
	return (0);
}

void	ft_do_redir_left_deep(t_info *info, int in)
{
	if (info->last_r[info->pip.curr_index] == 2)
	{
		close(in);
		in = open(".tmp", O_RDONLY, 0777);
		info->pip.in = in;
	}
}

int	ft_changevar(char **splited, t_list **vars, int len)
{
	(void)len;
	free((*vars)->content);
	(*vars)->content = ft_strdup(*splited);
	return (0);
}

int	ft_getlen(char *splited)
{
	int		len;

	len = 0;
	while (splited && splited[len] && splited[len] != '=')
		len++;
	return (len);
}

int	contain(char **cmd)
{
	while (*cmd)
		if (!ft_strncmp(*cmd++, "<<", 2))
			return (1);
	return (0);
}
