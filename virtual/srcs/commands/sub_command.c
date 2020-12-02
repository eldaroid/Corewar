/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:55:41 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 19:13:22 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_sub_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	res;

	res = read_varlen_be(pr->regs[run->args[A1]], sizeof(pr->regs[0]), SIGNED);
	res -= read_varlen_be(pr->regs[run->args[A2]], sizeof(pr->regs[0]), SIGNED);
	write_varlen_be(pr->regs[run->args[A3]], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
		ft_printf("P% 5d | sub r%ld r%ld r%ld\n", pr->id,
			run->args[A1] + 1, run->args[A2] + 1, run->args[A3] + 1);
}
