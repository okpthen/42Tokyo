
NAME = a.out
DEBUG = debug

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
# CXXFLAGS += -g -fsanitize=address
DEBUGFLAG = -g -fsanitize=address

FILES = Animal Cat Dog WrongAnimal WrongCat main
FILES_H = Animal Cat Dog WrongAnimal WrongCat
SRC = $(FILES:=.cpp)
HEADER = $(FILES_H:=.cpp)

OBJDIR = objs
OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))

RM = rm -rf
LEAK = valgrind --tool=memcheck

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@
	@echo $(BRIGHT_RED)
	@echo "────────█████─────────────█████"
	@echo "────████████████───────████████████"
	@echo "──████▓▓▓▓▓▓▓▓▓▓██───███▓▓▓▓▓▓▓▓▓████"
	@echo "─███▓▓▓▓▓▓▓▓▓▓▓▓▓██─██▓▓▓▓▓▓▓▓▓▓▓▓▓███"
	@echo "███▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███"
	@echo "██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██"
	@echo "██▓▓▓▓▓▓▓▓▓──────────────────▓▓▓▓▓▓▓▓██"
	@echo "██▓▓▓▓▓▓▓───████──████──████───▓▓▓▓▓▓██"
	@echo "██▓▓▓▓▓▓▓───██────█──█──█──█───▓▓▓▓▓▓██"
	@echo "███▓▓▓▓▓▓───██────████──████───▓▓▓▓▓▓██"
	@echo "███▓▓▓▓▓▓───██────█─────█──────▓▓▓▓▓▓██"
	@echo "─███▓▓▓▓▓───████──█─────█──────▓▓▓▓███"
	@echo "───███▓▓▓▓▓──────────────────▓▓▓▓▓▓███"
	@echo "────████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████"
	@echo "─────████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████"
	@echo "───────████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█████"
	@echo "──────────████▓▓▓▓▓▓▓▓▓▓▓▓████"
	@echo "─────────────███▓▓▓▓▓▓▓████"
	@echo "───────────────███▓▓▓███"
	@echo "─────────────────██▓██"
	@echo "──────────────────███\033[0m"

all: $(NAME)

$(DEBUG): $(OBJ) $(HEADER)
	$(CC) $(CCFLAGS) $(DEBUGFLAG) $(OBJ) -o $@

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME) $(DEBUG)

re: fclean all

echo:
	echo $(FILES) $(SRC) $(OBJ) $(HEADER)

test:
	@./$(NAME)

leak: $(NAME)
	$(LEAK) ./$(NAME)

.PHONY: all clean fclean re leak bonus









# color
RESET = "\033[0m"
# 標準色
BLACK = "\033[30m"
RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
BLUE = "\033[34m"
MAGENTA = "\033[35m"
CYAN = "\033[36m"
WHITE = "\033[37m"
# 明るい色
BRIGHT_BLACK = "\033[90m"
BRIGHT_RED = "\033[91m"
BRIGHT_GREEN = "\033[92m"
BRIGHT_YELLOW = "\033[93m"
BRIGHT_BLUE = "\033[94m"
BRIGHT_MAGENTA = "\033[95m"
BRIGHT_CYAN = "\033[96m"
BRIGHT_WHITE = "\033[97m"
# 背景色
BG_RED = "\033[41m"
BG_GREEN = "\033[42m"
BG_BLUE = "\033[44m"
BG_WHITE = "\033[47m"
# テキスト属性
BOLD = "\033[1m"
UNDERLINE = "\033[4m"
REVERSE = "\033[7m"
coffee:
	@echo ""
	@echo "                   ("
	@echo "                         )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
