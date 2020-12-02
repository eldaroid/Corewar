/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:14:20 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 18:14:21 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int	main(int argc, char **argv)
{
	t_com	*commands;
	t_ch	player;
	t_main	str_asm;

	if (argc > 1)
	{
		ft_check_extention(argv[argc - 1], &str_asm);
		init(argv[argc - 1], &commands, &player);
		assembler(commands, player, &str_asm);
		close(str_asm.fd);
		ft_printf("Writing output program to %s\n", str_asm.name);
		ft_strdel(&str_asm.name);
		free_commands(&commands);
		free_player(&player);
	}
	else
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	return (0);
}
