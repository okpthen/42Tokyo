SERVER = server
CLIENT = client
SRCC = srcs/ft_client.c srcs/ft_utils.c
OBJC = $(SRCC:.c=.o)
SRCS = srcs/ft_server.c srcs/ft_utils.c
OBJS = $(SRCS:.c=.o)

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
SRCC_BONUS = srcsb/ft_client_bonus.c srcsb/ft_utils_bonus.c
OBJC_BONUS = $(SRCC_BONUS:.c=.o)
SRCS_BONUS = srcsb/ft_sever_bonus.c srcsb/ft_utils_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

PRINTF_PATH = ./ft_printf/
PRINTF = ft_printf/libftprintf.a

RM = rm -f
AR = ar rc
CC = cc -Wall -Wextra -Werror #-g -fsanitize=address

all: $(SERVER) $(CLIENT)

%.o:%.c
	$(CC) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_PATH) all

$(CLIENT): $(OBJC)
	$(CC) $^ $(PRINTF) -o $@

$(SERVER): $(OBJS)
	$(CC) $^ $(PRINTF) -o $@

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJS_BONUS)
	$(CC) $^ $(PRINTF) -o $@

$(CLIENT_BONUS): $(OBJC_BONUS)
	$(CC) $^ $(PRINTF) -o $@

clean:
	$(RM) $(OBJC_BONUS) $(OBJS_BONUS) $(OBJC) $(OBJS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re