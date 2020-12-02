/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:39:56 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:40:06 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *alst, void *cmp, int (*f)(t_list *, void *))
{
	while (alst)
	{
		if (f(alst, cmp))
			return (alst);
		alst = alst->next;
	}
	return (NULL);
}
