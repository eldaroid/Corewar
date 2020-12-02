# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 17:56:20 by dmetallo          #+#    #+#              #
#    Updated: 2020/12/01 20:54:33 by fgracefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	asm

SRC 	=	src/adding.c \
			src/adding2.c \
			src/assembler.c \
			src/awm.c \
			src/frees.c \
			src/convertation.c \
			src/delete_comments.c \
			src/fill_instr.c \
			src/ft_exit.c \
			src/init_awm.c \
			src/main.c \
			src/my_librires_functions.c \
			src/check_args.c \
			src/ft_exit2.c \
			src/check_args_commands.c \
			src/check_args_commands2.c \
 			src/check_args_commands3.c \
			src/check_commands.c \
			src/check_commands2.c \
			src/check_commands3.c \
			src/check_labeles.c \
			src/what_is_it.c \
			src/what_is_it2.c

OP_C = ../common/op.c
OP_O = ./src/op.o

OBJS = $(SRC:%.c=%.o)

INCLUDES = 	$(LIBDIR)includes \
			$(PRINTF_DIR)includes\
			./includes \
			../common

INC_FLAG = $(addprefix -I, $(INCLUDES))

ALL_OBJ	= 	$(addprefix ./, $(OBJS))
LIBDIR	=	./../libft/
PRINTF_DIR = ./../ft_printf/

FLAGS		=	-Wall -Wextra -Werror -g

all: $(NAME)

%.o: %.c
				@gcc -c $< -o $@ $(INC_FLAG) $(FLAGS)

$(OP_O): $(OP_C) ../common/op.h
				@gcc -c $< -o $@ $(INC_FLAG) $(FLAGS)

$(NAME): $(LIBDIR)libft.a $(PRINTF_DIR)libftprintf.a $(ALL_OBJ) $(OP_O)
				@gcc $(FLAGS) $(ALL_OBJ) $(OP_O) -o $(NAME) -L $(LIBDIR) -lft -L $(PRINTF_DIR) -lftprintf

$(PRINTF_DIR)libftprintf.a: ft_printf

ft_printf:
				@make -C $(PRINTF_DIR)

$(LIBDIR)libft.a: libft

libft:
				@make -C $(LIBDIR)

clean:
				@make -C $(PRINTF_DIR) clean
				@make -C $(LIBDIR) clean
				@rm -rf $(ALL_OBJ)
				@rm -rf $(OP_O)

fclean:
				@make -C $(PRINTF_DIR) fclean
				@make -C $(LIBDIR) fclean
				@make clean
				@rm -rf ./asm

re: fclean all

.PHONY: re clean fclean all libft ft_printf
