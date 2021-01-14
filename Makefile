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

ASSEMBLY_FILES = asm.c is_input_correct.c main.c op.c convert_file.o two_s_complement_conv.o

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