/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_commands3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:15:38 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 18:15:41 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		check_ld(t_com *commands)
{
	if (commands->count_args != 2)
		return (0);
	return (check_ld_arg(commands));
}

int		check_st(t_com *commands)
{
	if (commands->count_args != 2)
		return (0);
	return (check_st_arg(commands));
}

int		check_add(t_com *commands)
{
	if (commands->count_args != 3)
		return (0);
	return (check_add_arg(commands));
}

int		check_sub(t_com *commands)
{
	if (commands->count_args != 3)
		return (0);
	return (check_sub_arg(commands));
}

int		check_and(t_com *commands)
{
	if (commands->count_args != 3)
		return (0);
	return (check_and_arg(commands));
}
