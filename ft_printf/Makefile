# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 13:51:05 by armoulin          #+#    #+#              #
#    Updated: 2019/04/11 13:41:34 by armoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

HEADERS_DIR	= ./includes/
HEADERS_LST	= printf.h \
			  libft.h \
			  get_next_line.h
HEADERS		= $(addprefix $(HEADERS_DIR), $(HEADERS_LST))

INCLUDES	= -I$(HEADERS_DIR)

SOURCES_DIR	= ./srcs/
SOURCES_LST	= ft_memset.c		ft_bzero.c			ft_memcpy.c \
			  ft_memccpy.c		ft_memmove.c		ft_memchr.c \
			  ft_memcmp.c		ft_strlen.c			ft_strdup.c \
			  ft_strcpy.c		ft_strncpy.c		ft_strcat.c \
			  ft_strncat.c		ft_strlcat.c		ft_strchr.c \
			  ft_strrchr.c		ft_strstr.c			ft_strnstr.c \
			  ft_strcmp.c		ft_strncmp.c		ft_atoi.c \
			  ft_isalpha.c		ft_isdigit.c		ft_isalnum.c \
			  ft_isascii.c		ft_isprint.c		ft_toupper.c \
			  ft_tolower.c		ft_memalloc.c		ft_memdel.c \
			  ft_strnew.c		ft_strdel.c			ft_strclr.c \
			  ft_striter.c		ft_striteri.c		ft_strmap.c \
			  ft_strmapi.c		ft_strequ.c			ft_strnequ.c \
			  ft_strsub.c		ft_strjoin.c		ft_strtrim.c \
			  ft_strsplit.c		ft_itoa.c			ft_putchar.c \
			  ft_putstr.c		ft_putendl.c		ft_putnbr.c \
			  ft_putchar_fd.c	ft_putstr_fd.c		ft_putendl_fd.c \
			  ft_putnbr_fd.c	ft_lstnew.c			ft_lstdelone.c \
			  ft_lstdel.c		ft_lstadd.c			ft_lstiter.c \
			  ft_lstmap.c		ft_isspace.c		ft_str_is_uppercase.c \
			  ft_islower.c		ft_isupper.c		ft_str_is_lowercase.c \
			  ft_lstpushback.c	ft_strupcase.c		ft_str_is_alpha.c \
			  ft_strlowcase.c	ft_tabiter_int.c 	ft_print_tab_int.c \
			  ft_itoa_base.c	ft_strcapitalize.c	ft_strndup.c \
			  ft_sqrt.c			ft_str_addi_back.c	ft_str_addi_front.c \
			  ft_ntoa_base.c	get_next_line.c		ft_imin.c \
			  ft_iabs.c			ft_dtoa.c			ft_atol.c \
			  parse.c			conversion.c		handle_mod.c \
			  printf.c			print_chars.c		print_sdeci.c \
			  print_udeci.c		print_oct.c			print_hex.c \
			  print_pointer.c	print_float.c		ft_imax.c \
			  ft_freetabsplit.c ft_str_contains.c 	ft_str_is_numeric.c \
			  ft_splitwhite.c
SOURCES		= $(addprefix $(SOURCES_DIR), $(SOURCES_LST))

OBJECTS_DIR	= ./bin/
OBJECTS_LST = $(patsubst %.c, %.o, $(SOURCES_LST))
OBJECTS		= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LST))

.PHONY: all, clean, fclean, re

all:				$(NAME)

$(NAME):			$(OBJECTS_DIR) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)binary files	compiled !$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME)	compiled !$(RESET)"

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIR)		created !$(RESET)"

$(OBJECTS_DIR)%.o:	$(SOURCES_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(OBJECTS_DIR)
	@echo "$(NAME): $(RED)$(OBJECTS_DIR)		deleted.$(RESET)"
	@echo "$(NAME): $(RED)binary files	deleted.$(RESET)"

fclean:				clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME)	deleted.$(RESET)"

re:					fclean all
