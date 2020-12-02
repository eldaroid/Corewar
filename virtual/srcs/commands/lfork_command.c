/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:55:22 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 19:13:22 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_lfork_run(t_vm *vm, t_process *pr, t_runner *run)
{
	copy_process(&vm->processes_root, pr, pr->pc + run->args[A1],
		&vm->process_count);
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
		ft_printf("P% 5d | lfork %ld (%ld)\n", pr->id,
			run->args[A1], pr->pc + run->args[A1]);
}
