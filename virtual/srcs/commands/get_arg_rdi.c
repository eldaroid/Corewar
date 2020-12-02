/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_rdi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:34:40 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/02 16:06:35 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_ulong			get_reg_dir_ind_arg(t_process *pr, t_runner *run, t_uint arg)
{
	t_ulong		val;

	if (run->types[arg] == REG_CODE)
		val = read_varlen_be(pr->regs[run->args[arg]], sizeof(pr->regs[0]),
			SIGNED);
	else if (run->types[arg] == DIR_CODE)
		val = run->args[arg];
	else
		val = read_be_map(run->field, pr->pc + (run->args[arg] % IDX_MOD),
			DIR_SIZE, SIGNED);
	return (val);
}
