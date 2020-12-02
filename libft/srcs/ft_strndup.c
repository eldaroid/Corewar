/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:49:55 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:50:00 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	length;
	char	*str;

	length = 0;
	while (s1[length] && length < n)
		length++;
	str = ft_strnew(length);
	if (str)
	{
		str[length] = 0;
		while (length > 0)
		{
			str[length - 1] = s1[length - 1];
			length--;
		}
	}
	return (str);
}
