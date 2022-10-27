/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:10:16 by risolon           #+#    #+#             */
/*   Updated: 2022/10/14 17:14:32 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(t_info *info, int code)
{
	if (code == 1)
	{
		ft_mshfree1(info, 1, -1);
		ft_putstr_fd("malloc error\n", 2);
		exit(1);
	}
	if (code == 2)
	{
		ft_putstr_fd("msh: syntax error near unexpected token '|'", 2);
		ft_putstr_fd("\n", 2);
	}
	if (code == 4)
	{
		ft_putstr_fd("minishell: parse error", 2);
		ft_putstr_fd("\n", 2);
	}
	return (1);
}
