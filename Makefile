# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 10:49:30 by anel-bou          #+#    #+#              #
#    Updated: 2021/01/10 17:46:44 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
LIB_COREWAR = corewar.a
LIBFT = libft/libft.a
FLAGS = #-Wall -Werror -Wextra
CC = gcc
OBJ = srcs/main.o srcs/isInputCorrect.o
INC_DIR = headers/
all: $(NAME)

$(NAME): $(LIBFT) $(LIB_COREWAR)
	@gcc srcs/main.c  $(LIB_COREWAR) $(LIBFT) -o $(NAME)
	
$(LIB_COREWAR): $(OBJ) corewar.h
	@ar rc $(LIB_COREWAR) $(OBJ)
	@ranlib $(LIB_COREWAR)

%.o : %.c
	@$(CC) -c $< -o $@

$(LIBFT): force
	@make -C libft/

force:

clean:
	@rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@rm -rf asm
	@make fclean -C libft/

re: fclean all

.PHONY: force fclean clean re all