/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:25:03 by ccamembe          #+#    #+#             */
/*   Updated: 2022/10/29 17:50:07 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_redir_left(char **cmd, int *lpipe, t_info *info)
{
	int	i;
	int	in;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i] && cmd[i][0] != '<')
		i++;
	if (cmd[i])
	{
		if (lpipe)
			close(lpipe[1]);
		if (lpipe)
			close(lpipe[0]);
		while (cmd[i][j] == '<')
			in = redirect_l(cmd[i++], info);
		ft_do_redir_left_deep(info, in);
		ft_set_read(NULL, in);
	}
	else if (lpipe)
		ft_set_read(lpipe, -1);
}

void	do_redir_right(char **cmd, int *rpipe, t_info *info)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i][0] != '>')
		i++;
	if (cmd[i])
	{
		redirect_r(cmd[i], info);
		if (rpipe)
			close(rpipe[0]);
		if (rpipe)
			close(rpipe[1]);
	}
	else if (rpipe)
		ft_set_write(rpipe, -1);
}

void	do_command(char **cmd, int *rpipe, t_info *info)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i][0] == '<')
		i++;
	while (cmd[i] && cmd[i][0] == '>')
		i++;
	if (!ft_strncmp("exit ", cmd[i], 5) || !ft_strncmp("exit", cmd[i], 5))
		exit(0);
	execute(cmd[i], info->env, info);
	close(rpipe[0]);
	close(rpipe[1]);
	exit(0);
}

int	ft_check_buildins(char **cmd, t_info *info, int count)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!ft_strncmp("exit ", cmd[i], 5) || !ft_strncmp("exit", cmd[i], 5))
			ft_exit(cmd[i], info);
		if (count == 1)
		{
			if (!ft_strncmp("export ", cmd[i], 7) \
			|| !ft_strncmp("export", cmd[i], 7))
				return (ft_export(cmd[i], info));
			if (!ft_strncmp("unset ", cmd[i], 6) \
			|| !ft_strncmp("unset", cmd[i], 6))
				return (ft_unset(cmd[i], info));
			if (!ft_strncmp("cd ", cmd[i], 3) \
			|| !ft_strncmp("cd", cmd[i], 3))
				return (ft_cd(cmd[i], info));
		}
		i++;
	}
	return (0);
}

int	get_count_cmd(char ***cmd)
{
	int	count;

	count = 0;
	while (cmd[count])
		count++;
	return (count);
}
