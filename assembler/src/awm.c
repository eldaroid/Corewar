/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:13:35 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 18:13:36 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"
#include "assembler.h"

void	set_player(t_ch *player, char *str)
{
	char *line;
	char *q;

	lst_create_player(str, player);
	q = NULL;
	line = NULL;
	while (get_row(player->fd, &line) > 0)
	{
		player->row++;
		init_line(&line, &q);
		if (is_dot_name(q))
			add_name(q, player);
		else if (is_dot_comment(q))
			add_comment(q, player);
		else if (q && *q && *q != '\0' && *q != '\n')
			ft_exit2(13, player->row);
		if (player->name != NULL && player->comment != NULL)
			break ;
		free_line(&line);
	}
	if (!player->name || !player->comment)
		ft_exit(14);
	free_line(&line);
}

void	work_with_label(char *q, t_com **commands,
		t_valid validator, t_ch player)
{
	add_label(q, *commands);
	if (!check_label((*commands)->label))
		ft_exit2(15, player.row);
	if (l_and_c_one_rows(q))
	{
		add_command_with_label(&q, *commands);
		if (is_valid_command((*commands)->name, validator, player.row))
		{
			add_args(&q, *commands, player);
			if (!check_args(*commands, validator))
				ft_exit2(18, player.row);
		}
		(*commands)->row = player.row;
		(*commands)->next = lst_create_commands();
		*commands = (*commands)->next;
	}
}

void	work_with_command(char *q, t_com **commands,
		t_valid validator, t_ch player)
{
	add_command(q, *commands);
	add_args(&q, *commands, player);
	(*commands)->row = player.row;
	if (!check_args(*commands, validator))
		ft_exit2(18, player.row);
	(*commands)->next = lst_create_commands();
	*commands = (*commands)->next;
}

void	set_commands(t_ch *player, t_com *commands)
{
	char		*line;
	char		*q;
	t_valid		validator;

	init_validator(&validator);
	while (get_row(player->fd, &line) > 0)
	{
		player->row++;
		init_line(&line, &q);
		if (it_s_label(q))
			work_with_label(q, &commands, validator, *player);
		else if (*q != '\0' && is_command(q, validator, player->row))
			work_with_command(q, &commands, validator, *player);
		else if (*q != '\0')
			ft_exit2(19, player->row);
		free_line(&line);
	}
	delete_comment(line);
	if (if_the_end_file_with_out_n(ft_strtrim(line)))
	{
		player->row++;
		ft_exit2(20, player->row);
	}
	free_line(&line);
}

void	init(char *argv, t_com **commands, t_ch *player)
{
	char		*line;
	t_com		*commands_head;
	int			row;

	line = NULL;
	*commands = lst_create_commands();
	commands_head = *commands;
	set_player(player, argv);
	set_commands(player, *commands);
	if (!(commands_head)->label && !(commands_head)->name)
		ft_exit2(21, 0);
	if ((row = check_labeles(commands_head)) != -1)
		ft_exit2(22, row);
	free_line(&line);
	*commands = commands_head;
	close(player->fd);
}
