/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:34:13 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:34:18 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_values(char *d1, char *d2, size_t elem_size)
{
	size_t	count;
	char	tmp;

	count = 0;
	while (count < elem_size)
	{
		tmp = d1[count];
		d1[count] = d2[count];
		d2[count] = tmp;
		count++;
	}
}

void		ft_bubble_sort(void *arr, size_t arr_size, size_t elem_size,
					int (*cmp)(const void *, const void *))
{
	char	*data;
	size_t	i;
	size_t	j;

	data = (char *)arr;
	i = 0;
	while (i < (arr_size - 1))
	{
		j = 0;
		while (j < (arr_size - i - 1))
		{
			if (cmp(data + j * elem_size, data + (j + 1) * elem_size) > 0)
				swap_values(data + j * elem_size, data + (j + 1) * elem_size,
					elem_size);
			j++;
		}
		i++;
	}
}
