# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 10:42:59 by anel-bou          #+#    #+#              #
#    Updated: 2021/03/06 10:47:34 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
LIBFT_FILE = libft.a

LIBFT_DIR = ./libft
ASSEMBLY_DIR = ./src/assembly
INC_DIR = ./includes/
LIBFT_INC = $(LIBFT_DIR)/
OBJ_DIR = ./obj

LFLAG = 

LIBFT = $(LIBFT_DIR)/$(LIBFT_FILE)

HEADERS = $(INC_DIR)corewar.h $(INC_DIR)op.h 

ASSEMBLY_FILES = is_input_correct.c\
				main.c\
				op.c\
				organize_beginning_data.c\
				tokenize_data.c\
				translate_data_to_code.c\
				analyze_line.c\
				get_operation_info.c\
				get_arguments_info.c\
				create_file.c\
				write_bytecode.c\
				liberate_memory.c

OBJ_ASSEMBLY = $(addprefix $(OBJ_DIR)/, $(ASSEMBLY_FILES:%.c=%.o))

CC = gcc
CFLAGS = -g #-Wall -Werror -Wextra 
INC = -I $(INC_DIR) -I $(LIBFT_INC)

all: $(NAME)

$(OBJ_DIR)/%.o: $(ASSEMBLY_DIR)/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ_ASSEMBLY)
	@make -C $(LIBFT_DIR)
	@$(CC) $(OBJ_ASSEMBLY) $(LIBFT) $(LFLAG) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all