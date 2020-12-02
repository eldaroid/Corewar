# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 18:39:31 by gdorcas           #+#    #+#              #
#    Updated: 2020/12/02 16:34:14 by fgracefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_printf.c \
		parse_flags.c \
		parse_width.c \
		parse_precision.c \
		parse_lenmod.c \
		parse_type.c \
		parse_format.c \
		parse_character.c \
		parse_string.c \
		add_to_out.c \
		add_paddings.c \
		add_prefix.c \
		add_unsigned.c \
		parse_unsigned.c \
		parse_signed.c \
		parse_double.c \
		add_double.c \
		calc_double.c \
		sub_functions.c \
		long_ariph.c \
		callbacks.c \
		parse_colors.c \
		main_funcs.c

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

INCLUDES = ./includes/ft_printf.h

SRCDIR	= ./srcs
OBJDIR	= ./objs

ALL_OBJ	= $(SRC:%.c=%.o)
OBJS	= $(addprefix $(OBJDIR)/, $(ALL_OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(CYAN) " - Compiling $(NAME)" $(EOC)
	@ar rc $@ $^
	@ranlib $@
	@echo $(GREEN) " - OK" $(EOC)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES) | $(OBJDIR)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean:
	@echo $(RED) " - Removing $(NAME) object files" $(EOC)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo $(RED) " - Removing $(NAME)" $(EOC)
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
