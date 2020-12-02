/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:35:39 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/02 16:05:21 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_ulong			get_dir_ind_arg(t_process *pr, t_runner *run, t_uint arg)
{
	t_ulong		val;

	if (run->types[arg] == DIR_CODE)
		val = run->args[arg];
	else
		val = read_be_map(run->field, pr->pc + (run->args[arg] % IDX_MOD),
			DIR_SIZE, SIGNED);
	return (val);
}
