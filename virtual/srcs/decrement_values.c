/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrement_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:18:46 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:04:32 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		dec_values(t_vm *vm)
{
	size_t			i;
	t_fieldelem		*elems;

	elems = vm->field;
	i = -1;
	while (++i < sizeof(vm->field) / sizeof(vm->field[0]))
	{
		if (elems[i].fresh)
			elems[i].fresh--;
		if (elems[i].live)
			elems[i].live--;
	}
}
