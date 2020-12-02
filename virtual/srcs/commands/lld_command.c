/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:55:28 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 19:13:22 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_lld_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	a1;

	a1 = 0;
	if (run->types[A1] == DIR_CODE)
		a1 = run->args[A1];
	else if (run->types[A1] == IND_CODE)
		a1 = read_be_map(vm->field, pr->pc + run->args[A1], DIR_SIZE / 2,
			SIGNED);
	write_varlen_be(pr->regs[run->args[A2]], a1, REG_SIZE);
	pr->carry = a1 == 0;
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
		ft_printf("P% 5d | lld %ld r%ld\n", pr->id,
			a1, run->args[A2] + 1);
}
