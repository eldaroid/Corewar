/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:20:05 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:04:34 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		start_pause(t_vm *vm)
{
	if (vm->state == PAUSED)
		vm->state = RUNNING;
	else if (vm->state == RUNNING)
		vm->state = PAUSED;
}
