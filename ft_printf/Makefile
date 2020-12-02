# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 18:39:31 by gdorcas           #+#    #+#              #
#    Updated: 2020/12/01 19:04:58 by gdorcas          ###   ########.fr        #
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
	ar rc $@ $^
	ranlib $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES) | $(OBJDIR)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
