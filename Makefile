# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 13:51:05 by armoulin          #+#    #+#              #
#    Updated: 2019/10/11 15:17:17 by armoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN					= \033[0;32m
RED						= \033[0;31m
RESET					= \033[0m

# NAMES
NAME_VM					= corewar
NAME_ASM				= asm

# COMPILER
CC						= gcc
CFLAGS					= -Wall -Wextra -Werror

# LIBS
LIBFT_DIR				= ./ft_printf/
LIBFT_HEAD				= $(LIBFT_DIR)includes/
LIBFT					= $(LIBFT_DIR)libftprintf.a

# HEADERS
HEADERS_DIR				= ./includes/
HEADERS_MUTUAL_LST		= op.h \
						  error.h
HEADERS_MUTUAL			= $(addprefix $(HEADERS_DIR), $(HEADERS_MUTUAL_LST))

HEADERS_VM_DIR			= $(HEADERS_DIR)virtual_machine/
HEADERS_VM_LST			= corewar.h
HEADERS_VM				= $(addprefix $(HEADERS_VM_DIR), $(HEADERS_VM_LST))

HEADERS_ASM_DIR			= $(HEADERS_DIR)assembler/
HEADERS_ASM_LST			= assembler.h
HEADERS_ASM				= $(addprefix $(HEADERS_ASM_DIR), $(HEADERS_ASM_LST))

# INCLUDES
INCLUDES				= -I$(HEADERS_DIR) -I$(HEADERS_VM_DIR) -I$(HEADERS_ASM_DIR) -I$(LIBFT_HEAD)
LIBRARIES				= -L$(LIBFT_DIR) -lftprintf

# SOURCES
SOURCES_DIR				= ./srcs/
SOURCES_MUTUAL_LST		= error.c \
						  op.c
SOURCES_MUTUAL			= $(addprefix $(SOURCES_DIR), $(SOURCES_MUTUAL_LST))

SOURCES_VM_DIR			= $(SOURCES_DIR)virtual_machine/
SOURCES_VM_LST			= main.c \
						  init_vm.c
SOURCES_VM				= $(addprefix $(SOURCES_VM_DIR), $(SOURCES_VM_LST))

SOURCES_ASM_DIR			= $(SOURCES_DIR)assembler/
SOURCES_ASM_LST			= main.c \
						  list_tools.c \
						  read_file.c \
						  get_header.c \
						  get_label.c \
						  get_op.c \
						  get_params.c \
						  check_params.c \
						  check_types.c \
						  check_labels.c
SOURCES_ASM				= $(addprefix $(SOURCES_ASM_DIR), $(SOURCES_ASM_LST))

# OBJECTS
OBJECTS_DIR				= ./bin/
OBJECTS_MUTUAL_LST		= $(patsubst %.c, %.o, $(SOURCES_MUTUAL_LST))
OBJECTS_MUTUAL			= $(addprefix $(OBJECTS_DIR), $(OBJECTS_MUTUAL_LST))

OBJECTS_VM_DIR			= $(OBJECTS_DIR)virtual_machine/
OBJECTS_VM_LST			= $(patsubst %.c, %.o, $(SOURCES_VM_LST))
OBJECTS_VM				= $(addprefix $(OBJECTS_VM_DIR), $(OBJECTS_VM_LST))

OBJECTS_ASM_DIR			= $(OBJECTS_DIR)assembler/
OBJECTS_ASM_LST			= $(patsubst %.c, %.o, $(SOURCES_ASM_LST))
OBJECTS_ASM				= $(addprefix $(OBJECTS_ASM_DIR), $(OBJECTS_ASM_LST))

# RULES
.PHONY: all, clean, fclean, re

all:					$(NAME_ASM) $(NAME_VM)

$(NAME_VM):				$(LIBFT) $(OBJECTS_VM_DIR) $(OBJECTS_MUTUAL) $(OBJECTS_VM)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS_MUTUAL) $(OBJECTS_VM) $(LIBRARIES) -o $@
	@echo "$(NAME_VM): $(GREEN)$(NAME_VM)		compiled.$(RESET)"

$(NAME_ASM):			$(LIBFT) $(OBJECTS_ASM_DIR) $(OBJECTS_MUTUAL) $(OBJECTS_ASM)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS_MUTUAL) $(OBJECTS_ASM) $(LIBRARIES) -o $@
	@echo "$(NAME_ASM): $(GREEN)$(NAME_ASM)		compiled.$(RESET)"

$(LIBFT):				FORCE
	@echo "$(NAME_VM): $(GREEN)Checking $(LIBFT)...$(RESET)"
	@make -sC $(LIBFT_DIR)

FORCE:

$(OBJECTS_ASM_DIR):		$(OBJECTS_DIR)
	@mkdir -p $(OBJECTS_ASM_DIR)
	@echo "$(NAME_ASM): $(GREEN)$(OBJECTS_ASM_DIR)		created.$(RESET)"

$(OBJECTS_VM_DIR):		$(OBJECTS_DIR)
	@mkdir -p $(OBJECTS_VM_DIR)
	@echo "$(NAME_VM): $(GREEN)$(OBJECTS_VM_DIR)		created.$(RESET)"

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)
	@echo "$(NAME_VM): $(GREEN)$(OBJECTS_DIR)		created.$(RESET)"

$(OBJECTS_DIR)%.o:		$(SOURCES_DIR)%.c $(HEADERS_MUTUAL)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(NAME_VM): $(GREEN)$@	compiled.$(RESET)"

$(OBJECTS_VM_DIR)%.o:	$(SOURCES_VM_DIR)%.c $(HEADERS_MUTUAL) $(HEADERS_VM)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(NAME_VM): $(GREEN)$@	compiled.$(RESET)"

$(OBJECTS_ASM_DIR)%.o:	$(SOURCES_ASM_DIR)%.c $(HEADERS_MUTUAL) $(HEADERS_ASM)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(NAME_ASM): $(GREEN)$@	compiled.$(RESET)"

clean:
	@make clean -sC $(LIBFT_DIR)
	@rm -rf $(OBJECTS_DIR)
	@echo "$(NAME_VM): $(RED)binary files	deleted.$(RESET)"
	@echo "$(NAME_VM): $(RED)$(OBJECTS_DIR)		deleted.$(RESET)"

fclean:					clean
	@make fclean -sC $(LIBFT_DIR)
	@rm -f $(NAME_VM) $(NAME_ASM)
	@echo "$(NAME_VM): $(RED)$(NAME_VM) and $(NAME_ASM)	deleted.$(RESET)"

re:						fclean all
