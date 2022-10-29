/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:38:04 by ccamembe          #+#    #+#             */
/*   Updated: 2022/10/29 18:55:28 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd_minus(t_info *info)
{
	char	*prev_dir;

	prev_dir = find_env("OLDPWD=", info);
	if (!prev_dir)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		return (1);
	}
	if (chdir(prev_dir) != 0)
	{
		free(prev_dir);
		ft_error_cmd("cd: ", NULL, errno);
		return (1);
	}
	else
		return (ft_cd_minus_helper(prev_dir, info));
}

int	ft_cd_deep_helper(char *current_dir, t_info *info, char **splited)
{
	char	cwd[PATH_MAX];
	char	*prev_dir;

	prev_dir = ft_strjoin("export OLDPWD=", current_dir);
	ft_export(prev_dir, info);
	free(prev_dir);
	free(current_dir);
	getcwd(cwd, PATH_MAX);
	current_dir = ft_strjoin("export PWD=", cwd);
	ft_export(current_dir, info);
	free(current_dir);
	ft_malloc_error(splited);
	set_envp(info);
	return (0);
}

int	ft_cd_helper(t_info *info, char **splited)
{
	char	*current_dir;

	current_dir = find_env("PWD=", info);
	if (chdir(splited[1]) != 0)
	{
		free(current_dir);
		ft_error_cmd("cd", splited[1], errno);
		ft_malloc_error(splited);
		return (1);
	}
	else
		return (ft_cd_deep_helper(current_dir, info, splited));
}

int	ft_cd(char *args, t_info *info)
{
	char	**splited;

	splited = ft_split_wquots(args);
	if (splited[1] == NULL)
	{
		ft_malloc_error(splited);
		return (chdir("/"));
	}
	else if (!ft_strcmp(splited[1], "-"))
	{
		ft_malloc_error(splited);
		return (ft_cd_minus(info));
	}
	else
		return (ft_cd_helper(info, splited));
}
