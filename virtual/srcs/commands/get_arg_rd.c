/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_rd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:35:01 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/02 16:06:10 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_ulong			get_reg_dir_arg(t_process *pr, t_runner *run, t_uint arg)
{
	t_ulong		val;

	if (run->types[arg] == REG_CODE)
		val = read_varlen_be(pr->regs[run->args[arg]], sizeof(pr->regs[0]),
			SIGNED);
	else
		val = run->args[arg];
	return (val);
}
