
NAME = PhoneBook

CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98
# CCFLAGS += -g -fsanitize=address
RM = rm -rf

OBJDIR = objs

FILES = contact main phonebook
SRC = $(FILES:=.cpp)
OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER = contact.hpp phonebook.hpp


LEAK = valgrind --tool=memcheck

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CCFLAGS) $(OBJ) -o $@

all: $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

echo:
	echo $(FILES) $(SRC) $(OBJ) $(HEADER)

test:
	@./$(NAME)

leak:
	$(LEAK) ./$(NAME)

.PHONY: all clean fclean re leak
