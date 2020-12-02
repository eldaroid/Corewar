# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 19:05:27 by fgracefo          #+#    #+#              #
#    Updated: 2020/12/02 16:41:42 by fgracefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR 	=	corewar
ASM			=	asm

ASM_DIR	=	./assembler/
VM_DIR	=	./virtual/

#						*****	COLLORS			*****
GREEN 		=	\033[0;32m
RED 		=	\033[0;31m 
YELLOW		=	\033[0;33m 
RESET 		= 	\033[0m

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

all:
				@make -C $(VM_DIR)
				@cp $(VM_DIR)corewar corewar
				@make -C $(ASM_DIR)
				@cp $(ASM_DIR)asm asm

clean:
				@make -C $(ASM_DIR) clean
				@make -C $(VM_DIR) clean

fclean: clean
				@echo $(RED) "delete all files..." $(GREEN) "OK!" $(EOC)
				@make -C $(ASM_DIR) fclean
				@make -C $(VM_DIR) fclean

				@rm -rf ./asm
				@rm -rf ./corewar

re: fclean all

.PHONY: re clean fclean all
