/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewblank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:42:37 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:42:43 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnewblank(size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)ft_memalloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->next = NULL;
	lst->content_size = content_size;
	if (content_size)
	{
		lst->content = ft_memalloc(content_size);
		if (lst->content == NULL)
			ft_memdel((void **)&lst);
	}
	return (lst);
}
