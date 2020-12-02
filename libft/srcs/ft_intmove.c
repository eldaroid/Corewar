/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:35:46 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:35:52 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intmove(int *dst, int *src, size_t size)
{
	if (dst < src)
	{
		while (size--)
			*dst++ = *src++;
	}
	else if (dst > src)
	{
		while (size--)
			dst[size] = src[size];
	}
}
