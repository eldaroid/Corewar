/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:24:14 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/02 16:03:48 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_visu(t_vm *vm)
{
	if (vm->visualize)
	{
		if (init_sdl(&vm->vis) != 0)
		{
			ft_putendl("Error initialize sdl");
			sdl_destroy(&vm->vis);
			vm->visualize = 0;
		}
		else
			vm->state = PAUSED;
	}
}
