# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 13:51:05 by armoulin          #+#    #+#              #
#    Updated: 2019/10/07 14:38:22 by lpoinsot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

NAME		= corewar

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= ./ft_printf/
LIBFT_HEAD	= $(LIBFT_DIR)includes/
LIBFT		= $(LIBFT_DIR)libftprintf.a

HEADERS_DIR	= ./includes/
HEADERS_LST	= corewar.h \
			  op.h \
			  error.h
HEADERS		= $(addprefix $(HEADERS_DIR), $(HEADERS_LST))

INCLUDES	= -I$(HEADERS_DIR) -I$(LIBFT_HEAD)
LIBRARIES	= -L$(LIBFT_DIR) -lftprintf

SOURCES_DIR	= ./srcs/
SOURCES_LST	= error.c \
			  init_vm.c \
			  main.c
SOURCES		= $(addprefix $(SOURCES_DIR), $(SOURCES_LST))

OBJECTS_DIR	= ./bin/
OBJECTS_LST	= $(patsubst %.c, %.o, $(SOURCES_LST))
OBJECTS		= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LST))

.PHONY: all, clean, fclean, re

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJECTS_DIR) $(OBJECTS)
	@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $@
	@echo "$(NAME): $(GREEN)$(NAME)		was compiled !$(RESET)"

$(LIBFT): FORCE
	@echo "$(NAME): $(GREEN)Checking $(LIBFT)...$(RESET)"
	@make -sC $(LIBFT_DIR)

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIR)		was created !$(RESET)"

$(OBJECTS_DIR)%.o:	$(SOURCES_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(NAME): $(GREEN)$@	was compiled !$(RESET)"

FORCE:

clean:
	@make clean -sC $(LIBFT_DIR)
	@rm -rf $(OBJECTS_DIR)
	@echo "$(NAME): $(RED)$(OBJECTS_DIR)		was deleted.$(RESET)"
	@echo "$(NAME): $(RED)binary files	were deleted.$(RESET)"


fclean:				clean
	@make fclean -sC $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME)		was deleted.$(RESET)"

re:					fclean all
