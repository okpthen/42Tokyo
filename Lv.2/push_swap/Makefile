CC = cc
CCS = cc -g -fsanitize=address
CCW = cc -Wall -Wextra -Werror
NAME = push_swap
CHEKER = checker

RM = rm -rf

OPERATION = srcs/operation/rotate.c srcs/operation/push_swap.c
SORT = srcs/sort/moving.c srcs/sort/solve_few.c srcs/sort/solve.c \
		srcs/sort/sort_b_4ele.c srcs/sort/sort_utils.c
UTILS = srcs/utils/check_duplicates.c srcs/utils/display..c srcs/utils/ft_atol.c \
		srcs/utils/ft_putstr.c srcs/utils/node.c srcs/utils/utils.c
SRCS = srcs/main.c $(OPERATION) $(SORT) $(UTILS)
SRCSB = srcsb/input_bonus.c srcsb/main_bonus.c srcsb/operate_bonus.c $(OPERATION) $(UTILS)

# SRCS = srcs/main.c srcs/sort/*.c srcs/utils/*.c srcs/operation/*.c
# SRCSB = srcsb/*.c srcs/utils/*.c srcs/operation/*.c

OBJ = $(SRCS:.c=.o)
OBJ_B = $(SRCSB:.c=.o)

# $(NAME): $(OBJ)

%.o:%.c
	$(CCW)  -c $< -o $@

$(NAME): $(OBJ)
	$(CCW) $(OBJ) -o $@

all: $(NAME)

	
allw: $(NAME)
	$(CCW) $(SRCS) -o $(NAME)


$(CHEKER): $(OBJ_B)
	$(CCW) $(OBJ_B) -o $@

bonus: $(CHEKER)


clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME) $(CHEKER)

re: fclean all bonus


# https://www.calc-site.com/randoms/integral 乱数

# 14 15 12 20 16 9 10 24 6 19 11 2 29 5 13 23 28 17 18 30 7 3 22 1 8 4 26 21 27 25

# 8 18 28 22 47 6 1 29 36 9 35 4 16 30 46 33 39 1 46 26 46 15 27 41 34 22 13 7 35 1 3 5 22 1 16 44 43 3 50 42 35 9 14 27 39 20 50 29 30 46

echo:
	@echo $(OBJ)


# SRCS = srcs/main.c srcs/operation/*.c srcs/sort/*.c srcs/utils/*.c
# SRCSB = srcsb/*.c srcs/operation/*.c srcs/utils/*.c
