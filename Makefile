ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so
LIB = libft_malloc_$(HOSTTYPE).so

# <=== LIBS ===>

LIBFT_NAME = libft.a

# <=== PATHS ===>

SRC_PATH = ./source/
SRC_MALLOC_IMPL_PATH = $(SRC_PATH)malloc_impl/
SRC_FREE_IMPL_PATH = $(SRC_PATH)free_impl/
SRC_HEAP_PATH = $(SRC_PATH)heap/
SRC_BLOCKS_PATH = $(SRC_PATH)blocks/
SRC_OUTPUT_PATH = $(SRC_PATH)output/
#SRC_<name>_PATH = $(SRC_PATH)<name>/

INC_PATH = ./headers/
#INC_<name>_PATH = $(INC_PATH)<name>/

LIB_PATH = ./libft/

# <=== SOURCES ===>

SRC_MALLOC_IMPL =	malloc.c \
					malloc_alloc.c \

SRC_HEAP =			heap_helpers.c \

SRC_BLOCKS =		blocks.c \
					blocks_usage.c \

SRC_OUTPUT =		show_alloc.c \

SRC_FREE_IMPL =		free.c \

#SRC_<name> =

# <=== OBJ ===>

OBJ_DIR = obj

OBJ_SRC_MALLOC_IMPL = $(addprefix $(OBJ_DIR)/, $(SRC_MALLOC_IMPL:.c=.o))
OBJ_SRC_FREE_IMPL = $(addprefix $(OBJ_DIR)/, $(SRC_FREE_IMPL:.c=.o))
OBJ_SRC_HEAP = $(addprefix $(OBJ_DIR)/, $(SRC_HEAP:.c=.o))
OBJ_SRC_BLOCKS = $(addprefix $(OBJ_DIR)/, $(SRC_BLOCKS:.c=.o))
OBJ_SRC_OUTPUT = $(addprefix $(OBJ_DIR)/, $(SRC_OUTPUT:.c=.o))
#OBJ_SRC_<name> = $(addprefix $(OBJ_DIR)/, $(SRC_<name>:.c=.o))

# <=== COMPILER ===>

CC = clang

INCLUDES = -I$(LIB_PATH)includes -I$(INC_PATH)

FLAGS = -g -std=c11 -Wall -Wextra -Werror $(INCLUDES)

TEST_FLAGS = -flat_namespace -I$(INC_PATH)

all: $(NAME)

$(NAME): $(LIB)
	@ln -s $^ $@

$(LIB): $(OBJ_SRC_MALLOC_IMPL) $(OBJ_SRC_HEAP) \
		$(OBJ_SRC_BLOCKS) $(OBJ_SRC_OUTPUT) \
		$(OBJ_SRC_FREE_IMPL)
	@make -C $(LIB_PATH)
	@$(CC) $(FLAGS) $(LIB_PATH)$(LIBFT_NAME) \
	$(OBJ_SRC_MALLOC_IMPL) $(OBJ_SRC_HEAP) \
	$(OBJ_SRC_BLOCKS) $(OBJ_SRC_OUTPUT) \
	$(OBJ_SRC_FREE_IMPL) \
	-shared -lpthread -o $@
	@echo "malloc ✅"

$(OBJ_DIR)/%.o : $(SRC_MALLOC_IMPL_PATH)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_FREE_IMPL_PATH)%.c
	@$(CC) $(FLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_HEAP_PATH)%.c
	@$(CC) $(FLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_BLOCKS_PATH)%.c
	@$(CC) $(FLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_OUTPUT_PATH)%.c
	@$(CC) $(FLAGS) -c -o $@ $<

tests: $(NAME)
	@$(CC) $(TEST_FLAGS) -o test_0 test/test_0.c
	@$(CC) $(TEST_FLAGS) -o test_1 test/test_1.c
	@$(CC) $(TEST_FLAGS) -L. -lft_malloc -o test_2 test/test_2.c
	@echo "tests ✅"

allt: tests

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_PATH) clean

fclean: clean
	@/bin/rm -f *.so
	@/bin/rm -f test_*
	@make -C $(LIB_PATH) fclean

re: fclean $(NAME)

.PHONY: clean all fclean re