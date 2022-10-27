/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:29:44 by risolon           #+#    #+#             */
/*   Updated: 2022/10/27 20:04:53 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer(t_info *info)
{
	if (ft_quot(info->line))
		return (ft_error(info, 4));
	printf("quot\n");
	if (check_pipes(info) || check_redir(info))
		return (ft_error(info, 4));
	printf("pipes redir\n");
	info->splited = ft_split_up(info->line, "|");
	printf("split\n");
	change_f_command(info);
	printf("f command\n");
	if (check_semicolon(info->splited))
	{
		ft_malloc_error(info->splited);
		return (ft_error(info, 4));
	}
	printf("semicolon\n");
	open_dollar(info);
	printf("$\n");
	if (!add_pipe(info))
		return (ft_error(info, 1));
	printf("add pipe\n");
	last_redir(info, info->commands);
	printf("last r\n");
	rebuild_redir(info);
	printf("rr\n");
	ft_cutter(info);
	printf("cutter\n");
	info->commands = modified_arg(info->commands);
	printf("m arg\n");
	info->commands = foo_bar(info->commands);
	printf("foo bar\n");
	info->cmd = create_cmd(info);
	printf("create cmd\n");
	if (info->splited)
		free(info->splited);
	printf("splited\n");
	return (0);
}
