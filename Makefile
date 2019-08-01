ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

# <=== LIBS ===>

LIBFT_NAME = libft.a

# <=== PATHS ===>

SRC_PATH = ./source/
SRC_MALLOC_IMPL_PATH = $(SRC_PATH)malloc_impl/
#SRC_<name>_PATH = $(SRC_PATH)<name>/

INC_PATH = ./headers/
#INC_<name>_PATH = $(INC_PATH)<name>/

LIB_PATH = ./libft/

# <=== SOURCES ===>

SRC =				main.c \

SRC_MALLOC_IMPL =	malloc.c \

#SRC_<name> =

# <=== OBJ ===>

OBJ_DIR = obj

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_SRC_MALLOC_IMPL = $(addprefix $(OBJ_DIR)/, $(SRC_MALLOC_IMPL:.c=.o))
#OBJ_SRC_<name> = $(addprefix $(OBJ_DIR)/, $(SRC_<name>:.c=.o))

# <=== COMPILER ===>

CC = clang

INCLUDES = -I$(LIB_PATH)includes -I$(INC_PATH)

FLAGS = -g -std=c11 -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_SRC_MALLOC_IMPL)
	@make -C $(LIB_PATH)
	@$(CC) $(FLAGS) $(LIB_PATH)$(LIBFT_NAME) \
	$(OBJ_SRC) $(OBJ_SRC_MALLOC_IMPL) \
	--shared -o $(NAME)
	@echo "malloc ✅"

$(OBJ_DIR)/%.o : $(SRC_PATH)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_MALLOC_IMPL_PATH)%.c
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_PATH) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean $(NAME)

.PHONY: clean all fclean re