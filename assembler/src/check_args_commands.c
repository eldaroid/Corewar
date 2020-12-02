/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:15:04 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 18:15:05 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		check_xor_arg(t_com *commands)
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

int		check_ldi_arg(t_com *commands)
{
	if (!check_arg_reg(commands->arg1) &&
		!check_arg_ind(commands->arg1) &&
		!check_arg_dir(commands->arg1))
		return (0);
	if (!check_arg_reg(commands->arg2) &&
		!check_arg_dir(commands->arg2))
		return (0);
	if (!check_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		check_lldi_arg(t_com *commands)
{
	if (!check_arg_reg(commands->arg1) &&
		!check_arg_ind(commands->arg1) &&
		!check_arg_dir(commands->arg1))
		return (0);
	if (!check_arg_reg(commands->arg2) &&
		!check_arg_dir(commands->arg2))
		return (0);
	if (!check_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		check_sti_arg(t_com *commands)
{
	if (!check_arg_reg(commands->arg1))
		return (0);
	if (!check_arg_reg(commands->arg2) &&
		!check_arg_dir(commands->arg2) &&
		!check_arg_ind(commands->arg2))
		return (0);
	if (!check_arg_reg(commands->arg3) &&
		!check_arg_dir(commands->arg3))
		return (0);
	return (1);
}

int		check_or_arg(t_com *commands)
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
