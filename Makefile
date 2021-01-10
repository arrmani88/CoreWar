# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 10:49:30 by anel-bou          #+#    #+#              #
#    Updated: 2021/01/10 12:57:14 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar.a
LIBFT = libft/libft.a
FLAGS = #-Wall -Werror -Wextra
CC = gcc
_OBJ = main.o
INC = headers/
OBJS_DIR = objs
OBJ = $(addprefix $(OBJS_DIR)/, ${_OBJ})
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) headers/corewar.h
	@ar rc $(NAME) $(OBJ) $(LIBFT)
	@ranlib $(NAME)
	@gcc srcs/main.c $(NAME) -o asm

$(OBJ): $(OBJS_DIR)/%.o : srcs/%.c  headers/corewar.h | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I. -Iheaders/

$(OBJS_DIR):
	mkdir $(OBJS_DIR);

$(LIBFT):
	@make -C libft
clean:
	@rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@rm -rf asm
	@make fclean -C libft/

re: fclean all
