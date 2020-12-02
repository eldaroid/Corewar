/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddblank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:38:52 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:38:58 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddblank(t_list **alst, size_t content_size)
{
	t_list	*newlist;

	newlist = NULL;
	if (alst)
	{
		newlist = (t_list *)ft_memalloc(sizeof(t_list));
		if (newlist == NULL)
			return (NULL);
		newlist->content_size = content_size;
		newlist->content = ft_memalloc(content_size);
		if (newlist->content == NULL)
		{
			ft_memdel((void **)&newlist);
			return (NULL);
		}
		newlist->next = *alst;
		*alst = newlist;
	}
	return (newlist);
}
