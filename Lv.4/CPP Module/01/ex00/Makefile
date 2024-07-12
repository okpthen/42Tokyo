
NAME = Zombie

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

OBJDIR = objs

FILES = main newZombie randomChump Zombie
SRC = $(FILES:=.cpp)
OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER = Zombie.hpp

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(OBJ) -o $@

all: $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

echo:
	echo $(FILES) $(SRC) $(OBJ) $(HEADER)

test:
	@./$(NAME)

.PHONY: all clean fclean re bonus norm