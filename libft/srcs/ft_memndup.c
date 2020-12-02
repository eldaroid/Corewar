/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:44:29 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:44:36 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memndup(const void *mem, size_t size)
{
	void	*m1;

	m1 = ft_memalloc(size);
	if (m1 && mem && size)
		ft_memcpy(m1, mem, size);
	return (m1);
}
