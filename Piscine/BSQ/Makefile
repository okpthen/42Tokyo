SRCS = srcs/*.c
INC = includes
CFLAGS = -Wall -Wextra -Werror
NAME = bsq

$(NAME):
	cc $(CFLAGS) $(SRCS) -o $(NAME) -I $(INC)

all: $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re