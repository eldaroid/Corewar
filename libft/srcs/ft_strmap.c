/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:56:11 by fgracefo          #+#    #+#             */
/*   Updated: 2020/10/28 18:48:16 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	l;
	unsigned int	i;
	char			*arr;

	if (!s || !f)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	arr = (char*)malloc(l + 1);
	if (!arr)
		return (NULL);
	while (*s)
		arr[i++] = (*f)(*s++);
	arr[i] = '\0';
	return (arr);
}
