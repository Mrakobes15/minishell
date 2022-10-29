/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:48:27 by risolon           #+#    #+#             */
/*   Updated: 2022/10/29 20:06:08 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_error;

void	print_cmd(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	parser(t_info *info)
{
	//ft_reinit_pip(info);
	printf("start\n");
	info->line = readline("minishell> ");
	printf("rl\n");
	if (info->line == NULL)
		ft_sigex(info);
	printf("line\n");
	if (info->line[0] == '\0')
		return (ft_mshfree1(info, 1, -1));
	if (*info->line && ft_strlen(info->line))
		add_history(info->line);
	printf("his\n");
	if (ft_space_check(info->line))
		return (ft_mshfree1(info, 1, -1));
	printf("space\n");
	if (lexer(info) == 1)
		return (ft_mshfree1(info, 1, 2));
	if (info->cmd == NULL)
		return (ft_mshfree1(info, 1, 1));
	printf("cmd check\n");
	signal(SIGINT, sig_void);
	printf("sig\n");
	if (info->cmd == NULL)
		ft_skip(info);
	else
		pipex(info->cmd, info);
	printf("pipe\n");
	ft_mshfree1(info, 2, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	init(&info, argc, argv, envp);
	set_envp(&info);
	while (!info.exit)
	{
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, sig_handler);
		parser(&info);
	}
	return (0);
}
