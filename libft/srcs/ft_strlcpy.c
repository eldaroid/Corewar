/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:49:22 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:49:27 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len;

	len = 0;
	if (dst && src)
	{
		len = ft_strlen(src);
		while (size > 1 && *src)
		{
			*dst++ = *src++;
			size--;
		}
		if (size)
			*dst = '\0';
	}
	return (len);
}
