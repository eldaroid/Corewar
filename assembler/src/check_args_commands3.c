/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_commands3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:15:15 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 18:15:19 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		check_live(t_com *commands)
{
	if (commands->count_args != 1)
		return (0);
	return (check_arg_dir(commands->arg1));
}

int		check_ld_arg(t_com *commands)
{
	if (!check_arg_dir(commands->arg1) &&
		!check_arg_ind(commands->arg1))
		return (0);
	if (!check_arg_reg(commands->arg2))
		return (0);
	return (1);
}
