/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:25:07 by fgracefo          #+#    #+#             */
/*   Updated: 2020/11/01 20:28:07 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	if (!s)
		return (0);
	if (!(fresh = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		fresh[i] = s[i + start];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
