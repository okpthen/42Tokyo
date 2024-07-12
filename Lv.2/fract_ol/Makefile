NAME = fractol
CC = cc -Wall -Wextra -Werror #-g -fsanitize=address
SRC = src/main.c src/utils/ft_putstr.c src/utils/ft_strncmp.c src/drow.c src/hook.c src/calcutate.c\
		src/calculate_bonus.c src/calculate_bonus2.c src/coler/coler.c src/zoom_move.c
OBJ = $(SRC:.c=.o)

RM = rm -rf

%.o:%.c
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o fractol

all: $(NAME)

SAMPLE = sample.c
SAMPLEO = sample.o
sample: $(SAMPLEO)
	$(CC) $(SAMPLEO) -lmlx -framework OpenGL -framework AppKit -o sample

TEST = test.c
TESTO = test.o
test: $(TESTO)
	$(CC) $(TESTO) -lmlx -lXext -lX11 -lm -o test


clean:
	$(RM) $(OBJ) $(SAMPLEO) $(TESTO)

fclean: clean
	$(RM) fractol test sample

re: fclean all
