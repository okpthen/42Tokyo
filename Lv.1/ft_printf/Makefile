# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 20:30:47 by kazuhiro          #+#    #+#              #
#    Updated: 2024/04/08 06:38:37 by kazuhiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
SRC				=	ft_print_hex.c ft_print_memory.c ft_print_utils.c ft_printf.c ft_check.c
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a
OBJC			=	$(SRC:%.c=%.o)
AR				=	ar rc
RM				=	rm -rf

$(NAME): $(OBJC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJC) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJC)

all: $(NAME)

bonus:	all

clean:
	$(RM) $(OBJC)
	make -C $(LIBFT_PATH) clean
	$(RM) a.out

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re:					fclean all

echo:
	echo $(SRC)
	echo $(OBJC)
	echo $(NAME)
	echo $(CC) $(CFLAGS) $(LIBFT) $(AR) $(RM)

.PHONY:				all bonus clean fclean re libft


SRCS = ft_print_hex.c ft_print_memory.c ft_print_utils.c ft_printf.c

