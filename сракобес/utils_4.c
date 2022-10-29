/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamembe <ccamembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:01:41 by risolon           #+#    #+#             */
/*   Updated: 2022/10/28 20:06:52 by ccamembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

int	*make_array(char **argv)
{
	int	*files;
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (argv[++i])
	{
		if (!strncmp(argv[i], ">>", 2))
			count++;
		else if (!strncmp(argv[i], ">", 1))
			count++;
	}
	files = malloc((count + 1) * sizeof(int));
	if (!files)
		ft_error(NULL, 1);
	return (files);
}

int	open_file_h(char *redir, char *file, int flag)
{
	int	fd;

	fd = -2;
	if (!ft_strncmp(redir, ">>", 2) && file)
		fd = open(file, \
		O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (!ft_strncmp(redir, ">", 1) && file)
		fd = open(file, \
		O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (!flag)
		close(fd);
	return (fd);
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("\0", 0);
		rl_redisplay();
		g_error = 1;
	}
}

void	sig_void(int sig)
{
	(void)sig;
}

void	sig_void2(int sig)
{
	(void)sig;
	g_error = 1;
	rl_on_new_line();
	rl_redisplay();
	rl_catch_signals = 0;
	close(0);
	exit(0);
}
