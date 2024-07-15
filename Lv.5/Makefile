NAME = ircserv
DEBUG = debug

CLIENT = ircclient
BIRCD = bircd/bircd
BIRCDDIR = bircd/

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
DEBUGFLAG = -g -fsanitize=address
INCLUDES = -I$(HEADERDIR)

FILES = Client Server Channel Command Error SocketServer
SRCFILE = main.cpp
HEADERFILE = irc.hpp

SRCFILE += $(FILES:=.cpp)
SRCDIR = src
SRC = $(addprefix $(SRCDIR)/, $(SRCFILE))

HEADERFILE += $(FILES:=.hpp)
HEADERDIR = inc
HEADER = $(addprefix $(HEADERDIR)/, $(HEADERFILE))

OBJDIR = objs
OBJ = $(addprefix $(OBJDIR)/, $(SRCFILE:.cpp=.o))

RM = rm -rf
LEAK = valgrind --tool=memcheck

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@
	echo "/connect 127.0.0.1 5000 0000"

all: $(NAME)

$(DEBUG): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAG) $(OBJ) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(CLIENT):
	$(MAKE) -C $(BIRCDDIR)
	mv $(BIRCD) ./$@

clean:
	$(RM) $(OBJDIR)

fclean:
	$(RM) $(OBJDIR)
	$(RM) $(NAME) $(DEBUG) $(CLIENT)

re: fclean all

echo:
	echo $(FILES) $(SRC) $(OBJ) $(HEADER)

test:
	@./$(NAME)

leak: $(NAME)
	$(LEAK) ./$(NAME)

con:
	echo "/connect 127.0.0.1 5000 0000"

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
