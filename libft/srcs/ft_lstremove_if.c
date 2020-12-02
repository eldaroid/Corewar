/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:43:20 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:43:26 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstremove_if(t_list **root, int (*cmp)(void *, void *), void *sec)
{
	t_list	*ret;
	t_list	*lst;

	ret = NULL;
	while (*root)
	{
		lst = *root;
		if (cmp(lst->content, sec) == 0)
		{
			ret = lst;
			*root = lst->next;
			lst->next = NULL;
			break ;
		}
		root = &lst->next;
	}
	return (ret);
}
