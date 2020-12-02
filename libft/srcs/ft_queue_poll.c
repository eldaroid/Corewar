/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_poll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:46:24 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:46:30 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delone(void *data, size_t content_size)
{
	(void)content_size;
	(void)data;
}

int			ft_queue_poll(t_ftqueue **queue, void **data)
{
	while (*queue)
	{
		if ((*queue)->next == 0)
		{
			*data = (*queue)->content;
			ft_lstdelone(queue, delone);
			return (0);
		}
		queue = &((*queue)->next);
	}
	return (1);
}
