/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:46:03 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:46:08 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_queue_add(t_ftqueue **queue, void *data)
{
	t_ftqueue *newq;

	if (queue)
	{
		newq = ft_lstnewblank(0);
		if (newq)
		{
			newq->content = data;
			newq->next = *queue;
			*queue = newq;
			return (0);
		}
	}
	return (1);
}
