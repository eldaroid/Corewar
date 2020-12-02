/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:48:03 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:48:08 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stack_pop(t_ftstack *stack, void **data)
{
	void	*d;

	if (ft_array_size(stack))
	{
		if (ft_array_get(stack, stack->num_elems - 1, &d) == 0)
		{
			stack->num_elems--;
			*data = d;
			return (0);
		}
	}
	return (1);
}
