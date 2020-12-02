/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:16:06 by fgracefo          #+#    #+#             */
/*   Updated: 2020/11/01 20:24:21 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_find_words(char *str, char c, int *index)
{
	int			i;
	int			start;
	int			end;
	char		*dest;

	start = *index;
	i = start;
	while (!(str[i] == c))
		if (str[i] != '\0')
			i++;
		else
			break ;
	end = i;
	dest = (char*)malloc(end - start + 1);
	if (str[i] == c)
		i++;
	*index = i;
	i = 0;
	while (i < end - start)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
