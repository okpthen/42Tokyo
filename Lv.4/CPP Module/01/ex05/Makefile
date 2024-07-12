
NAME = Harl

CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98
# CCFLAGS += -g -fsanitize=address
RM = rm -rf

OBJDIR = objs

FILES = Harl main
SRC = $(FILES:=.cpp)
OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER = Harl.hpp


LEAK = valgrind --tool=memcheck

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CCFLAGS) $(OBJ) -o $@
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
	@echo "──────────────────███"

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
