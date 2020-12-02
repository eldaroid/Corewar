/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:45:25 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 19:13:22 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void			destroy_all(t_vm *vm)
{
	t_process		*pr;
	t_process		*prnext;

	while (vm->count_players--)
		ft_memdel((void **)&vm->players[vm->count_players]);
	while (vm->count_pl_tmp--)
		ft_memdel((void **)&vm->players[vm->count_pl_tmp]);
	pr = vm->processes_root;
	vm->processes_root = NULL;
	while (pr)
	{
		prnext = pr->next;
		ft_memdel((void **)&pr);
		pr = prnext;
	}
	sdl_destroy(&vm->vis);
}
