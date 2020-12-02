/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:05:39 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:04:36 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_vm(t_vm *vm)
{
	t_uint		i;
	t_uint		j;
	t_player	*pl;
	t_uint		start;

	i = -1;
	while (++i < vm->count_players)
	{
		pl = vm->players[i];
		start = ((sizeof(vm->field) / sizeof(*vm->field)) / vm->count_players)
			* i;
		j = -1;
		while (++j < pl->prog_size)
		{
			vm->field[start + j].cmd = pl->prog[j];
			vm->field[start + j].id = pl->player_id;
		}
		add_process(&vm->processes_root, pl->player_id, start,
			&vm->process_count);
		vm->last_player = pl;
	}
	vm->state = RUNNING;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->cycles_check = vm->cycle_to_die;
	init_visu(vm);
}
