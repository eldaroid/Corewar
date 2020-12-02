/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:00:01 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/01 20:59:07 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_AWM_H
# define COREWAR_AWM_H

# include "libft.h"
# include "op.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

# define BLACK(string)			"\x1b[30m" string "\x1b[0m"
# define RED(string)			"\x1b[31m" string "\x1b[0m"
# define GREEN(string)			"\x1b[32m" string "\x1b[0m"
# define YELLOW(string)			"\x1b[33m" string "\x1b[0m"
# define BLUE(string)			"\x1b[34m" string "\x1b[0m"
# define MAGENTA(string)		"\x1b[35m" string "\x1b[0m"
# define CYAN(string)			"\x1b[36m" string "\x1b[0m"
# define GREY(string)			"\x1b[37m" string "\x1b[0m"
# define RESET(string)			"\x1b[0m" string "\x1b[0m"

typedef struct			s_commands
{
	char				*name;
	char				*arg1;
	char				*arg2;
	char				*arg3;
	char				*label;
	int					count_args;
	int					row;
	int					num_byte;
	int					num_byte_from_start;
	unsigned char		code_arg;
	struct s_commands	*next;
}						t_com;

typedef struct			s_champ
{
	char				*name;
	char				*comment;
	int					fd;
	int					row;
}						t_ch;

typedef	struct			s_valid
{
	int					(*valid_com[16])(t_com *commands);
	char				can_use_command[16][8];
}						t_valid;

int						ft_is_strstr(char *src, char *to_find);
int						check_fork(t_com *commands);
int						check_lfork(t_com *commands);
int						check_lld(t_com *commands);
int						check_aff(t_com *commands);
int						check_args(t_com *commands, t_valid validator);
int						check_lld_arg(t_com *commands);
int						check_arg_dir(char	*str);
int						check_arg_reg(char *str);
int						check_sti(t_com *commands);
int						check_sti_arg(t_com *commands);
int						check_or(t_com *commands);
int						check_xor(t_com *commands);
int						check_zjmp(t_com *commands);
int						check_ldi(t_com *commands);
int						check_lldi(t_com *commands);
int						check_xor_arg(t_com *commands);
int						check_ldi_arg(t_com *commands);
int						check_lldi_arg(t_com *commands);
int						check_or_arg(t_com *commands);
int						check_ld_arg(t_com *commands);
int						check_st_arg(t_com *commands);
int						check_add_arg(t_com *commands);
int						check_sub_arg(t_com *commands);
int						check_and_arg(t_com *commands);
int						check_ld(t_com *commands);
int						check_st(t_com *commands);
int						check_add(t_com *commands);
int						check_sub(t_com *commands);
int						check_and(t_com *commands);
int						check_live(t_com *commands);
int						check_arg_ind(char *str);
int						is_command(char *line, t_valid validator, int row);
int						it_s_label(char *line);
int						is_valid_command(char *command,
	t_valid validator, int row);
int						is_label(char *str, t_com *commands);
int						is_dot_comment(char *line);
void					add_comment(char *str, t_ch *player);
void					ft_exit2(int num, int row);
void					add_with_n_comment(t_ch *player, char *str, int z);
int						is_dot_name(char *line);
void					add_name(char *str, t_ch *player);
void					add_with_n_name(t_ch *player, char *str, int z);
void					add_args(char **line, t_com *commands, t_ch player);
void					add_command_with_label(char **line, t_com *command);
void					add_command(char *line, t_com *command);
void					add_label(char *line, t_com *commands);
void					init_command(t_valid *validator);
void					init_validator(t_valid *validator);
t_com					*lst_create_commands(void);
int						check_label(char *label);
void					ft_delete_tabs(char *str);
void					free_commands(t_com **coms);
void					free_line(char **str);
void					free_player(t_ch *player);
int						check_labeles(t_com *head);
int						l_and_c_one_rows(char *line);
void					delete_comment(char *str);
void					set_player(t_ch *player, char *str);
void					set_commands(t_ch *player, t_com *commands);
void					work_with_command(char *q, t_com **commands,
	t_valid validator, t_ch player);
void					work_with_label(char *q, t_com **commands,
	t_valid validator, t_ch player);
void					set_player(t_ch *player, char *str);
void					init_line(char **line, char **q);
void					adding_args(char **args, t_com *commands);
void					end_name_or_comment(char **str, int i,
	t_ch *player, int z);
int						ft_where_is_n(char *s);
int						ft_give_row(char **str, char **line, int fd);
int						get_row(const int fd, char **line);
int						if_the_end_file_with_out_n(char *line);
void					lst_create_player(char *str, t_ch *player);
void					init(char *argv, t_com **commands, t_ch *player);
void					delete_comment_and_tabs(char *str);
void					ft_exit2(int num, int row);
void					errors_code2(int num);
void					errors_code3(int num);

#endif
