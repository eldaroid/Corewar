/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:44:39 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:04:41 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	checks that the next argument after "-d" or "-dump" exists
**	checks the next argument after "-d" or "-dump" for correct cycle number
**	using safe atoi fucntion and sets the mode of dump return (32 or 64 bits)
**	increments the index +1
*/

static t_result		check_dump(t_vm *vm, int *index, int ac, char *av[])
{
	if (*index + 1 < ac && ft_safe_atoi(av[*index + 1], &vm->dump_n) ==
		FT_ATOI_OK && vm->dump_n >= 0)
	{
		vm->do_dump = !ft_strcmp(av[*index], "-d") ? 32 : 64;
		(*index)++;
	}
	else
		return (ERR_INCORRECT_DUMPARG);
	return (RET_OK);
}

/*
**	checks that next 2 arguments after "-n" exist
**	checks the next argument after "-n" for correct player index
**	sends the i+2 argument to read_champ function
**	increments the index +2
*/

static t_result		check_order_flag(t_vm *vm, int *index, int ac, char *av[])
{
	int			res;
	t_player	*player;
	t_result	err;

	if (*index + 2 < ac && ft_safe_atoi(av[*index + 1], &res) ==
		FT_ATOI_OK && res >= 1 && res <= MAX_PLAYERS &&
		is_player_index_free(vm->players, res, sizeof(vm->players)))
	{
		if ((err = read_champ(av[*index + 2], &player, res)) == RET_OK)
		{
			vm->players[res - 1] = player;
			(*index) += 2;
			vm->count_players++;
		}
		else
			return (err);
	}
	else
		return (ERR_INCORRECT_NARG);
	return (RET_OK);
}

static t_result		check_debug(t_vm *vm, int *index, int ac, char *av[])
{
	int		res;

	vm->do_debug = 1;
	if (*index + 1 < ac && ft_safe_atoi(av[*index + 1], &res) ==
		FT_ATOI_OK && res >= 0 && res <= FT_INTMAX)
	{
		vm->debug_args = res;
		(*index)++;
	}
	else
		return (ERR_INCORRECT_VARG);
	return (RET_OK);
}

static t_result		read_arg_champ(t_vm *vm, const int *index, char *av[])
{
	int			res;
	t_player	*player;
	t_result	err;

	err = get_next_free_index(vm->pl_tmp, &res, sizeof(vm->pl_tmp));
	if (err != RET_OK)
		return (err);
	if ((err = read_champ(av[*index], &player, res)) != RET_OK)
		return (err);
	vm->pl_tmp[res - 1] = player;
	vm->count_pl_tmp++;
	return (RET_OK);
}

/*
**	parses
*/

t_result			parse_arg(t_vm *vm, int *index, int ac, char *av[])
{
	t_result	err;

	err = RET_OK;
	if (!ft_strcmp(av[*index], "-d") || !ft_strcmp(av[*index], "-dump"))
		err = check_dump(vm, index, ac, av);
	else if (!ft_strcmp(av[*index], "-n"))
		err = check_order_flag(vm, index, ac, av);
	else if (!ft_strcmp(av[*index], "-s"))
		vm->visualize = 1;
	else if (!ft_strcmp(av[*index], "-v"))
		err = check_debug(vm, index, ac, av);
	else if (!ft_strcmp(av[*index], "-a"))
		vm->print_aff = 1;
	else
		err = read_arg_champ(vm, index, av);
	return (err);
}
