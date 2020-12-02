/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:29:55 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:29:56 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_array_get(t_ftarray *arr, size_t index, void **data)
{
	if (index < arr->num_elems)
	{
		*data = arr->data[index];
		return (0);
	}
	return (1);
}
