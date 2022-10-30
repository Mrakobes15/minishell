/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:29:44 by risolon           #+#    #+#             */
/*   Updated: 2022/10/30 14:45:45 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

int	lexer(t_info *info)
{
	signal(SIGINT, sig_void);
	if (ft_quot(info->line))
		return (ft_error(info, 4));
	if (check_pipes(info) || check_redir(info))
		return (ft_error(info, 4));
	info->splited = ft_split_up(info->line, "|");
	change_f_command(info);
	if (check_semicolon(info->splited))
	{
		ft_malloc_error(info->splited);
		return (ft_error(info, 4));
	}
	open_dollar(info);
	g_error = 0;
	if (!add_pipe(info))
		return (ft_error(info, 1));
	last_redir(info, info->commands);
	rebuild_redir(info);
	ft_cutter(info);
	info->commands = modified_arg(info->commands);
	info->commands = foo_bar(info->commands);
	info->cmd = create_cmd(info);
	if (info->splited)
		free(info->splited);
	return (0);
}
