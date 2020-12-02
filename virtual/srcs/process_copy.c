/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:05:30 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/02 16:07:35 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process		*copy_process(t_process **root, t_process *copy, long pc,
	size_t *count)
{
	t_process *process;

	process = add_process(root, copy->player_id, pc, count);
	if (process)
	{
		ft_memcpy(process->regs, copy->regs, sizeof(copy->regs));
		process->carry = copy->carry;
		process->cycle_live = copy->cycle_live;
	}
	return (process);
}
