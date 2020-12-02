/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:02:24 by fgracefo          #+#    #+#             */
/*   Updated: 2020/11/01 20:25:32 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if ((!dst && !src) || !n)
		return (dst);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (d);
}
