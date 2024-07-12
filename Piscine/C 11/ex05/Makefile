SRCS = srcs/*.c
DO-OP = do-op
INC = includes

$(DO-OP):
	cc -Wall -Wextra -Werror $(SRCS) -o $(DO-OP) -I $(INC)

all: $(DO-OP)

clean:

fclean:
	rm -rf do-op

re: fclean all

.PHONY: all clean fclean re