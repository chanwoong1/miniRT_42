# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:49:21 by sunhwang          #+#    #+#              #
#    Updated: 2023/01/27 13:31:14 by sunhwang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libmlx.dylib

OBJ_DIR		= obj/

MODULE_SRC	= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ	= $(MODULE_SRC:%.swift=$(OBJ_DIR)%.swiftmodule)

SRC			= interface.swift $(MODULE_SRC)
OBJ			= $(SRC:%.swift=$(OBJ_DIR)%.o)

C_SRC		= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ		= $(C_SRC:%.c=$(OBJ_DIR)%.o)
CFLAGS		= -O3

INC			= -Iobj

all: $(NAME)

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	@swiftc $(OPTI) -o $@ -emit-library $(OBJ) $(C_OBJ) -lz
	@echo "$(MAGENTA)╔══════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(MAGENTA)║        Minilibx compile finished.        ║$(DEF_COLOR)"
	@echo "$(MAGENTA)╚══════════════════════════════════════════╝$(DEF_COLOR)"

$(C_OBJ): $(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(MAGENTA)Compiling... \t$< $(DEF_COLOR)"

$(OBJ): $(OBJ_DIR)%.o: %.swift
	@swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@
	@echo "$(MAGENTA)Compiling... \t$< $(DEF_COLOR)"

$(MODULE_OBJ): $(OBJ_DIR)%.swiftmodule: %.swift
	@mkdir -p $(@D)
	@swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)
	@echo "$(MAGENTA)Compiling... \t$< $(DEF_COLOR)"

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(MAGENTA)MLX archive files has been deleted.$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
ORANGE = \033[38;5;208m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
