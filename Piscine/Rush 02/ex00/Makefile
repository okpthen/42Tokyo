SRCS = srcs/check_dict.c srcs/convert_numset.c srcs/create_dict.c srcs/utils.c \
	srcs/ft_putstr.c srcs/ft_split.c srcs/main.c srcs/put_answer.c srcs/put_answer2.c srcs/read_file.c
NAME = rush-02
INC = includes
# CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror

$(NAME):
	cc $(CFLAGS) $(SRCS) -o $(NAME) -I $(INC)

all: $(NAME)

fclean:
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
