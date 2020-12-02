/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:15:27 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 18:15:28 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		check_sti(t_com *commands)
{
	if (commands->count_args != 3)
		return (0);
	return (check_sti_arg(commands));
}

int		check_fork(t_com *commands)
{
	if (commands->count_args != 1)
		return (0);
	return (check_arg_dir(commands->arg1));
}

int		check_lfork(t_com *commands)
{
	if (commands->count_args != 1)
		return (0);
	return (check_arg_dir(commands->arg1));
}

int		check_lld(t_com *commands)
{
	if (commands->count_args != 2)
		return (0);
	return (check_lld_arg(commands));
}

int		check_aff(t_com *commands)
{
	if (commands->count_args != 1)
		return (0);
	return (check_arg_reg(commands->arg1));
}
