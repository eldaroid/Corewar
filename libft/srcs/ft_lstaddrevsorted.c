/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddrevsorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:39:12 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:39:17 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddrevsorted(t_list **root, t_list *node, void *param,
						int (*cmp)(t_list *, t_list *, void *))
{
	t_list **prev;
	t_list *lst;

	if (!root || !node || !cmp)
		return ;
	lst = *root;
	prev = root;
	while (lst)
	{
		if (cmp(lst, node, param) < 0)
			break ;
		prev = &(lst->next);
		lst = lst->next;
	}
	node->next = lst;
	*prev = node;
}
