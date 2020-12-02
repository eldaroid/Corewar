/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:30:37 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:30:38 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_init(t_ftarray *ftarray, size_t init_val)
{
	if (ftarray)
	{
		if (init_val == 0)
			init_val = 64;
		ft_bzero(ftarray, sizeof(t_ftarray));
		ftarray->init_val = init_val;
		return (0);
	}
	return (1);
}
