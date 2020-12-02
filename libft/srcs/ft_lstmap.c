/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:02 by fgracefo          #+#    #+#             */
/*   Updated: 2020/11/01 20:25:03 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_list_clear(t_list **begin_list)
{
	t_list		*tmp;

	while (*begin_list)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	*begin_list = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*temp;
	t_list		*gb;
	t_list		*new;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!(new = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	gb = new;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(new->next = ft_lstnew(temp->content, temp->content_size)))
		{
			free(new->next);
			ft_list_clear(&gb);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (gb);
}
