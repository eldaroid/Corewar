/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:55:33 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 19:13:22 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_or_run(t_vm *vm, t_process *pr, t_runner *run)
{
	t_ulong		val1;
	t_ulong		val2;
	t_ulong		res;

	val1 = get_reg_dir_ind_arg(pr, run, A1);
	val2 = get_reg_dir_ind_arg(pr, run, A2);
	res = val1 | val2;
	write_varlen_be(pr->regs[run->args[A3]], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
		ft_printf("P% 5d | or %ld %ld r%ld\n", pr->id,
			val1, val2, run->args[A3] + 1);
}
