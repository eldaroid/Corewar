/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_comments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:13:49 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 18:13:50 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

void	delete_comment(char *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"' && str[i] != '\0')
				i++;
		}
		if (str[i] == '\0')
			return ;
		if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
		{
			str[i] = '\0';
			return ;
		}
		i++;
	}
}

void	delete_comment_and_tabs(char *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i] != '\0')
				i++;
		}
		if (str[i] == '\t')
			str[i] = ' ';
		if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
		{
			str[i] = '\0';
			return ;
		}
		i++;
	}
}
