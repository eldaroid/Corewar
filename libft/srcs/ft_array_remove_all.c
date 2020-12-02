/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_remove_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:32:35 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:32:52 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_remove_all(t_ftarray *arr, void (*f)(void *))
{
	while (arr->num_elems)
	{
		if (f)
			f(arr->data[arr->num_elems - 1]);
		arr->num_elems--;
	}
	ft_memdel((void **)&arr->data);
	arr->max_elems = 0;
}
