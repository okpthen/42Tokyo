CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
INC_DIR = includes

SRC_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(SRC_DIR)/, $(OBJ_FILES))
INC = -I$(INC_DIR)

TARGET = libft.a

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c | $(SRC_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
