/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:17:59 by fgracefo          #+#    #+#             */
/*   Updated: 2020/11/01 20:24:53 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nnext;
	t_list	*tnnext;

	if (!*alst)
		return ;
	nnext = *alst;
	while (nnext)
	{
		tnnext = nnext->next;
		del(nnext->content, nnext->content_size);
		free(nnext);
		nnext = tnnext;
	}
	*alst = NULL;
}
