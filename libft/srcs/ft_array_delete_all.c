/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_delete_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:28:54 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:28:55 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_delete_all(t_ftarray **arr, void (*f)(void *))
{
	t_ftarray	*ftarray;

	ftarray = *arr;
	if (ftarray)
	{
		if (f)
		{
			while (ftarray->num_elems)
			{
				f(ftarray->data[ftarray->num_elems - 1]);
				ftarray->num_elems--;
			}
		}
		ft_memdel((void **)&ftarray->data);
		ft_memdel((void **)arr);
	}
}
