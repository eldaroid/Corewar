/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:31:48 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:31:49 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ftarray	*ft_array_new(size_t init_val)
{
	t_ftarray	*ftarray;

	ftarray = (t_ftarray *)ft_memalloc(sizeof(*ftarray));
	if (ftarray)
	{
		ft_array_init(ftarray, init_val);
	}
	return (ftarray);
}
