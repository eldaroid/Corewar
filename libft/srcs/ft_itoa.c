/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:51:02 by fgracefo          #+#    #+#             */
/*   Updated: 2020/11/01 20:24:41 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*itog;
	int			i;
	short		znak;
	int			pow;

	znak = (n < 0) ? 2 : 1;
	i = 1;
	pow = 1;
	while ((n / pow / 10) != 0 && ++i)
		pow = pow * 10;
	if (!(itog = malloc(sizeof(char) * (unsigned long)(i + znak))))
		return (NULL);
	i = 0;
	if (znak == 2 && (znak = -1))
		itog[i++] = '-';
	while (pow != 0)
	{
		itog[i++] = (char)((int)n / pow * znak + '0');
		n = n % pow;
		pow = pow / 10;
	}
	itog[i++] = '\0';
	return (itog);
}
