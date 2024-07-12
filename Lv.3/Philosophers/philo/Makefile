NAME = philo
SRCDIR = srcs srcs/philosophers srcs/utils srcs/time_gremreaper
SRCS   = $(foreach SRCDIR,$(SRCDIR),$(wildcard $(SRCDIR)/*.c))
OBJ = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
# CFLAGS += -g -fsanitize=thread
# CFLAGS += -g -fsanitize=address
RM = rm -rf

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)
	@$(RM) a.out
fclean: clean
	$(RM) $(NAME)

re: fclean all

sanitize: $(OBJ)
	$(CC) -g -fsanitize=address $(OBJ) -o $(NAME)

echo:
	@echo $(OBJ)

1:
	./$(NAME) 1 800 200 200

2:
	./$(NAME) 5 800 200 200

3:
	./$(NAME) 5 800 200 200 3

4:
	./$(NAME) 4 410 200 200

5:
	./$(NAME) 4 310 200 100

6:
	./$(NAME) 10 800 200 200 7

7:
	./$(NAME) 200 415 200 200 7