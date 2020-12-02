/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_indir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:15:57 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:22:16 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_ind(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;

	valid = INVALID;
	if (op->args[id] & T_IND)
	{
		runner->args[id] = read_be_map(runner->field, pr->pc + runner->skip,
			IND_SIZE, SIGNED);
		valid = VALID;
	}
	runner->skip += IND_SIZE;
	return (valid);
}
