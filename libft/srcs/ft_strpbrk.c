/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:50:20 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:50:27 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	const char	*set;

	while (*s)
	{
		set = charset;
		while (*set)
		{
			if (*set == *s)
				return ((char *)s);
			set++;
		}
		s++;
	}
	return (NULL);
}
