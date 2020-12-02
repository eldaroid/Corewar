/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:16:16 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/02 16:06:56 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_reg(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;
	long	r;

	valid = INVALID;
	if (op->args[id] & T_REG)
	{
		r = read_be_map(runner->field, pr->pc + runner->skip, 1, SIGNED);
		if (r >= 1 && r <= REG_NUMBER)
		{
			runner->args[id] = r - 1;
			valid = VALID;
		}
	}
	runner->skip++;
	return (valid);
}
