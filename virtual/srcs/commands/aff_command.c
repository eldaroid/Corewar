/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:55:08 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 19:13:22 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_aff_run(t_vm *vm, t_process *pr, t_runner *run)
{
	if (vm->print_aff)
		ft_printf("Aff: %c\n", pr->regs[run->args[A1]][REG_SIZE - 1]);
}
