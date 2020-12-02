/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:29:25 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:29:26 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_array_foreach(t_ftarray *arr, void (*f)(void *, void *), void *param)
{
	size_t	count;

	count = 0;
	while (count < arr->num_elems)
	{
		f(arr->data[count], param);
		count++;
	}
	return (0);
}
