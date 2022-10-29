/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:25:22 by ccamembe          #+#    #+#             */
/*   Updated: 2022/10/29 20:08:06 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fork_and_chain(int *lpipe, int *rpipe, char **cmd, t_info *info)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		exit(1);
	else if (!pid)
	{
		signal(SIGINT, sig_void2);
		rl_catch_signals = 1;
		do_redir_left(cmd, lpipe, info);
		signal(SIGINT, sig_handler);
		do_redir_right(cmd, rpipe, info);
		do_command(cmd, rpipe, info);
	}
	else
	{
		if (contain(cmd))
			waitpid(pid, NULL, 0);
		else
			waitpid(pid, NULL, WNOHANG);
	}
	info->pip.curr_index++;
	return (pid);
}

int	pipe_cycle(char ***cmd, t_info *info, int i)
{
	int	pid;

	pipe(info->pip.rpipe);
	pid = fork_and_chain(info->pip.lpipe, info->pip.rpipe, cmd[i], info);
	close(info->pip.lpipe[0]);
	close(info->pip.lpipe[1]);
	info->pip.lpipe[0] = info->pip.rpipe[0];
	info->pip.lpipe[1] = info->pip.rpipe[1];
	i++;
	return (pid);
}

void	if_count_no_one(int i, int flag, char ***cmd, t_info *info)
{
	if (info->count != 1 && flag == 1)
	{
		info->pip.lpipe[0] = info->pip.rpipe[0];
		info->pip.lpipe[1] = info->pip.rpipe[1];
	}
	if (info->count != 1 && flag == 2)
	{
		info->pid = fork_and_chain(info->pip.lpipe, NULL, cmd[i], info);
		close(info->pip.lpipe[0]);
		close(info->pip.lpipe[1]);
	}
}

void	pipex(char ***cmd, t_info *info)
{
	int	i;
	int	count;
	int	pid;
	int	status;

	count = get_count_cmd(cmd);
	i = 1;
	info->count = count;
	if (count != 1)
		pipe(info->pip.rpipe);
	pid = fork_and_chain(NULL, info->pip.rpipe, cmd[0], info);
	if_count_no_one(i, 1, cmd, info);
	while (i < count - 1)
		pid = pipe_cycle(cmd, info, i++);
	info->pid = pid;
	if_count_no_one(i, 2, cmd, info);
	waitpid(info->pid, &status, 0);
	ft_convert_error(WEXITSTATUS(status));
	if ((!cmd[++i] && count != 1 && WEXITSTATUS(status) != 2) \
	|| (WEXITSTATUS(status) != 2 && count == 1))
		ft_check_buildins(cmd[count - 1], info, count);
	//ft_reinit_pip(info);
}
