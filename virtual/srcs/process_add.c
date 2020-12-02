/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:05:24 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/02 16:05:29 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process		*add_process(t_process **root, t_uint id, long pc,
	size_t *count)
{
	static size_t	max_index;
	t_process		*process;

	process = ft_memalloc(sizeof(*process));
	if (process)
	{
		while (pc < 0)
			pc += MEM_SIZE;
		process->id = ++max_index;
		process->next = *root;
		process->prev = NULL;
		process->player_id = id;
		process->pc = (int)pc;
		write_varlen_be(process->regs[0], -id, REG_SIZE);
		if (*root)
			(*root)->prev = process;
		*root = process;
		(*count)++;
	}
	return (process);
}
