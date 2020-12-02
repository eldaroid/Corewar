/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:44:58 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:45:04 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *data, size_t old_size, size_t new_size)
{
	void	*new_mem;

	new_mem = ft_memalloc(new_size);
	if (new_mem)
		if (data)
			ft_memcpy(new_mem, data, old_size);
	ft_memdel(&data);
	return (new_mem);
}
