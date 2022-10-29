/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:24:50 by ccamembe          #+#    #+#             */
/*   Updated: 2022/10/29 17:48:47 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_helper(char *arg, t_info *info)
{
	if (!ft_strncmp("pwd ", arg, 4) || !ft_strncmp("pwd", arg, 4))
		ft_pwd();
	if (!ft_strncmp("env ", arg, 4) || !ft_strncmp("env", arg, 4))
		get_env(info);
	if (info->count != 1)
	{
		if (!ft_strncmp("export ", arg, 7) || !ft_strncmp("export", arg, 7))
			exit(ft_export(arg, info));
		if (!ft_strncmp("unset ", arg, 6) || !ft_strncmp("unset", arg, 6))
			exit(ft_unset(arg, info));
		if (!ft_strncmp("cd ", arg, 3) || !ft_strncmp("cd", arg, 3))
			exit(ft_cd(arg, info));
	}
	else
	{
		if (!ft_strncmp("export ", arg, 7) || !ft_strncmp("export", arg, 7) \
		|| !ft_strncmp("unset ", arg, 6) || !ft_strncmp("unset", arg, 6) \
		|| !ft_strncmp("cd ", arg, 3) || !ft_strncmp("cd", arg, 3))
			exit(0);
	}
	if (!ft_strncmp("echo ", arg, 5) || !ft_strncmp("echo", arg, 5))
		ft_echo(arg, info);
	return (0);
}

void	ft_reinit_pip(t_info *info)
{
	close(info->pip.lpipe[0]);
	close(info->pip.lpipe[1]);
	close(info->pip.rpipe[0]);
	close(info->pip.rpipe[1]);
	close(info->pip.in);
	info->pip.lpipe[0] = -1;
	info->pip.lpipe[1] = -1;
	info->pip.rpipe[0] = -1;
	info->pip.rpipe[1] = -1;
	info->pip.in = -1;
}

void	ft_set_read(int *lpipe, int in)
{
	if (lpipe)
	{
		dup2(lpipe[0], STDIN_FILENO);
		close(lpipe[0]);
		close(lpipe[1]);
	}
	else
	{
		dup2(in, STDIN_FILENO);
		close(in);
	}
}

void	ft_set_write(int *rpipe, int out)
{
	if (rpipe)
	{
		dup2(rpipe[1], STDOUT_FILENO);
		close(rpipe[0]);
		close(rpipe[1]);
	}
	else
	{
		dup2(out, STDOUT_FILENO);
		close(out);
	}
}
