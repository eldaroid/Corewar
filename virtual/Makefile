# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 17:10:00 by gdorcas           #+#    #+#              #
#    Updated: 2020/12/02 16:48:38 by fgracefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ALL_C =	check_args.c\
		check_op_dir.c \
		check_op_indir.c \
		check_op_reg.c \
		cycle_process.c \
		decrement_values.c \
		dump_print.c \
		errors.c \
		free_all.c \
		increment_cycles.c \
		parse.c \
		pause.c \
		process_add.c \
		process_copy.c \
		process_execution.c \
		process_removal.c \
		read_arg.c \
		read_be.c \
		read_champion.c \
		visual_init.c \
		vm_init.c \
		vm.c \
		commands/add_command.c \
		commands/aff_command.c \
		commands/and_command.c \
		commands/fork_command.c\
		commands/get_arg_di.c \
		commands/get_arg_rd.c \
		commands/get_arg_rdi.c \
		commands/ld_command.c \
		commands/ldi_command.c \
		commands/lfork_command.c \
		commands/live_command.c \
		commands/lld_command.c \
		commands/lldi_command.c \
		commands/or_command.c \
		commands/st_command.c \
		commands/sti_command.c \
		commands/sub_command.c \
		commands/xor_command.c \
		commands/zjmp_command.c \
		visual/deinit.c \
		visual/draw_all.c \
		visual/draw_carriages.c \
		visual/draw_info.c \
		visual/get_color.c \
		visual/init.c \
		visual/print.c \
		visual/process.c \
		visual/reload_carriages.c \
		visual/reload_fonts.c

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

SRCDIR = ./srcs
OBJDIR = ./objs

LIBFT_DIR = ./../Libft

LIBFTPRINTF_DIR = ./../ft_printf

ALL_OBJ = $(ALL_C:%.c=%.o)

OBJS = $(addprefix $(OBJDIR)/, $(ALL_OBJ))

COMMON_OBJS = $(addprefix $(OBJDIR)/, common/op.o)

NAME = corewar

INCLUDES =	./includes \
			./../common \
			$(LIBFT_DIR)/includes \
			$(LIBFTPRINTF_DIR)/includes

HEADER_FILES = ./includes/errors.h \
			./includes/visual.h \
			./includes/vm.h \
			./../common/op.h

INCS = $(addprefix -I, $(INCLUDES)) `sdl2-config --cflags`

LIB_DIR =	$(LIBFT_DIR)\
			$(LIBFTPRINTF_DIR) \

LIB_DIR_FLAG = $(addprefix -L,$(LIB_DIR))

LIBS = 		ft \
			ftprintf \
			SDL2 \
			SDL2_ttf \
			SDL2_gfx \
			m

LIBS_FLAG = $(addprefix -l,$(LIBS)) `sdl2-config --libs`

COMP_LIBFT = @make -C $(LIBFT_DIR)

COMP_LIBFTPRINTF = @make -C $(LIBFTPRINTF_DIR)

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(LIBFTPRINTF_DIR)/libftprintf.a $(OBJS) $(COMMON_OBJS)
	@echo $(CYAN) " - Compiling $(NAME)" $(EOC)
	@gcc $(FLAGS) $(OBJS) $(COMMON_OBJS) $(LIB_DIR_FLAG) $(LIBS_FLAG) -o $@
	@echo $(GREEN) " - OK" $(EOC)

$(OBJDIR):
	@echo $(PURPLE) " - Making $(OBJDIR) folders" $(EOC)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/visual
	@mkdir -p $(OBJDIR)/commands
	@mkdir -p $(OBJDIR)/common

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER_FILES) | $(OBJDIR)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@gcc $(FLAGS) $(INCS) -c $< -o $@

$(COMMON_OBJS): ./../common/op.c $(HEADER_FILES)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@gcc $(FLAGS) $(INCS) -c $< -o $@

$(LIBFT_DIR)/libft.a: libft

libft:
	$(COMP_LIBFT)

$(LIBFTPRINTF_DIR)/libftprintf.a: ft_printf

ft_printf:
	$(COMP_LIBFTPRINTF)

clean:
	@echo $(RED) " - Removing $(NAME) object files" $(EOC)
	@rm -rf $(OBJDIR)
	@$(COMP_LIBFT) clean

fclean: clean
	@echo $(RED) " - Removing $(NAME)" $(EOC)
	@rm -rf $(NAME)
	@$(COMP_LIBFT) fclean

re: fclean all

.PHONY: lib clean fclean all re
