/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_it2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:16:03 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 18:16:04 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		is_valid_command(char *command, t_valid validator, int row)
{
	int i;

	i = 0;
	while (i < 16 && command)
	{
		if (ft_strcmp(command, validator.can_use_command[i]) == 0)
			return (1);
		i++;
	}
	ft_exit2(16, row);
	return (0);
}

int		l_and_c_one_rows(char *line)
{
	int i;

	i = 0;
	while (line[i] != LABEL_CHAR)
		i++;
	if (line[i + 1] && line[i + 1] != '\0')
		return (1);
	return (0);
}

int		if_the_end_file_with_out_n(char *line)
{
	char *q;

	q = ft_strtrim(line);
	free_line(&line);
	if (q && ft_strcmp(q, "\0") == 0)
	{
		free_line(&q);
		return (0);
	}
	free_line(&q);
	return (1);
}
