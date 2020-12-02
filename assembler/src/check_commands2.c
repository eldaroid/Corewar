/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_commands2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:15:33 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 18:15:34 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		check_or(t_com *commands)
{
	if (commands->count_args != 3)
		return (0);
	return (check_or_arg(commands));
}

int		check_xor(t_com *commands)
{
	if (commands->count_args != 3)
		return (0);
	return (check_xor_arg(commands));
}

int		check_zjmp(t_com *commands)
{
	if (commands->count_args != 1)
		return (0);
	return (check_arg_dir(commands->arg1));
}

int		check_ldi(t_com *commands)
{
	if (commands->count_args != 3)
		return (0);
	return (check_ldi_arg(commands));
}

int		check_lldi(t_com *commands)
{
	if (commands->count_args != 3)
		return (0);
	return (check_lldi_arg(commands));
}
