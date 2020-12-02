/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_removal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:05:33 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/02 16:06:27 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			remove_process(t_process **root, t_process *pr, size_t *count)
{
	if (pr->prev)
		pr->prev->next = pr->next;
	if (pr->next)
		pr->next->prev = pr->prev;
	if (pr == *root)
		*root = pr->next;
	ft_memdel((void **)&pr);
	(*count)--;
}
