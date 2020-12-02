/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:50:43 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:50:49 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	len;
	size_t	index;
	char	c;

	if (str)
	{
		index = 0;
		len = ft_strlen(str);
		while (index < (len / 2))
		{
			c = str[index];
			str[index] = str[len - index - 1];
			str[len - index - 1] = c;
			index++;
		}
	}
	return (str);
}
