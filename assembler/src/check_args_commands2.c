/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_commands2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:15:07 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 18:15:10 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		check_lld_arg(t_com *commands)
{
	if (!check_arg_dir(commands->arg1) &&
		!check_arg_ind(commands->arg1))
		return (0);
	if (!check_arg_reg(commands->arg2))
		return (0);
	return (1);
}

int		check_st_arg(t_com *commands)
{
	if (!check_arg_reg(commands->arg1))
		return (0);
	if (!check_arg_reg(commands->arg2) &&
		!check_arg_ind(commands->arg2))
		return (0);
	return (1);
}

int		check_add_arg(t_com *commands)
{
	if (!check_arg_reg(commands->arg1) ||
		!check_arg_reg(commands->arg2) ||
		!check_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		check_sub_arg(t_com *commands)
{
	if (!check_arg_reg(commands->arg1) ||
		!check_arg_reg(commands->arg2) ||
		!check_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		check_and_arg(t_com *commands)
{
	if (!check_arg_reg(commands->arg1) &&
		!check_arg_ind(commands->arg1) &&
		!check_arg_dir(commands->arg1))
		return (0);
	if (!check_arg_reg(commands->arg2) &&
		!check_arg_ind(commands->arg2) &&
		!check_arg_dir(commands->arg2))
		return (0);
	if (!check_arg_reg(commands->arg3))
		return (0);
	return (1);
}
