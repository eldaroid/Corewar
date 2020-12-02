/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:15:35 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:22:02 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_dir(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;
	t_uint	size;

	valid = INVALID;
	size = op->is_tdir_2bytes ? DIR_SIZE / 2 : DIR_SIZE;
	if (op->args[id] & T_DIR)
	{
		runner->args[id] = read_be_map(runner->field, pr->pc + runner->skip,
			size, SIGNED);
		valid = VALID;
	}
	runner->skip += size;
	return (valid);
}
