/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:33:13 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:33:21 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_array_remove(t_ftarray *arr, size_t index, void (*f)(void *))
{
	void	*data;

	if (index < arr->num_elems)
	{
		data = arr->data[index];
		arr->num_elems--;
		if (arr->num_elems - index > 0)
		{
			ft_voidcpy(arr->data + index, arr->data + index + 1,
				arr->num_elems - index);
		}
		if (f)
			f(data);
		return (0);
	}
	return (1);
}
