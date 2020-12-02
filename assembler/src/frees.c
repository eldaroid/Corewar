/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:17:41 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 18:17:42 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

void	free_commands(t_com **coms)
{
	t_com *q;

	if (!(*coms))
		return ;
	while (*coms && (*coms)->next)
	{
		q = *coms;
		(*coms) = (*coms)->next;
		free(q->name);
		free(q->arg2);
		free(q->arg1);
		free(q->arg3);
		free(q->label);
		free(q);
	}
	free((*coms)->name);
	free((*coms)->arg2);
	free((*coms)->label);
	free((*coms)->arg1);
	free((*coms)->arg3);
	free(*coms);
}

void	free_line(char **str)
{
	if (str && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

void	free_player(t_ch *player)
{
	free(player->name);
	free(player->comment);
}
