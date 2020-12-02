/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:55:16 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 19:13:22 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_ld_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	a1;

	a1 = get_dir_ind_arg(pr, run, A1);
	write_varlen_be(pr->regs[run->args[A2]], a1, sizeof(pr->regs[0]));
	pr->carry = a1 == 0;
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
		ft_printf("P% 5d | ld %ld r%ld\n", pr->id, a1, run->args[A2] + 1);
}
