NAME   =  minishell
CC     = cc
CFLAGS =  -Wall -Wextra -Werror # -g  -fsanitize=address
HEAD   = includes
LIBFT  = ./libft/libft.a
RM     = rm -f

SRCDIR = ./srcs ./srcs/cmd_lst srcs/LexerParser ./srcs/exec ./srcs/builtin ./srcs/loop ./srcs/env
SRCS   = $(foreach SRCDIR,$(SRCDIR),$(wildcard $(SRCDIR)/*.c))

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -I $(HEAD) -lncurses -lreadline

$(LIBFT):
	$(MAKE) bonus -C ./libft

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

debug: fclean $(LIBFT)
	$(CC) -g -o $(NAME) $(SRCS) $(LIBFT) -I $(HEAD) -lncurses
	lldb ./minishell

sanitize: fclean $(LIBFT)
	$(CC)  -g -fsanitize=address -o $(NAME) $(SRCS) $(LIBFT) -I $(HEAD) -lncurses -lreadline

re: fclean all
.PHONY: all clean fclean re debug add sanitize 
