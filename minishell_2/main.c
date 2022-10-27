/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:48:27 by risolon           #+#    #+#             */
/*   Updated: 2022/10/27 20:06:11 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	int		i;
	// char	*line;

	i = 0;
	// line = NULL;
	printf("enteraance\n");
	info->line = readline("minishell> ");
	printf("read cmd\n");
	if (info->line == NULL)
		exit(1);
	printf("NULL\n");
	if (info->line[0] == '\0')
		return (ft_mshfree1(info, 1, -1));
	printf("zero\n");
	// if (*info->line && ft_strlen(info->line))
	// 	add_to_history(info->line);
	if (ft_space_check(info->line))
		return (ft_mshfree1(info, 1, -1));
	printf("space\n");
	if (lexer(info) == 1)
		return (ft_mshfree1(info, 1, 2));
	printf("lexer\n");
	if (info->cmd == NULL)
		return (ft_mshfree1(info, 1, 1));
	printf("cmd\n");
	if (info->cmd)
	{
		while (info->cmd[i])
		{
			print_cmd(info->cmd[i]);
			i++;
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	init(&info, argc, argv, envp);
	set_envp(&info);
	printf("hi\n");
	while (!info.exit)
	{
		printf("cycle\n");
		//signal(SIGINT, sig_handler);
		//signal(SIGQUIT, sig_handler);
		parser(&info);
	}
	return (0);
}
