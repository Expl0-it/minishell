NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I ./
LDFLAGS = -lreadline
RM = rm -f
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = main.c $(filter-out $(wildcard libft/*.c), $(wildcard */*.c))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS) $(IFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

${LIBFT}:
	make -C ${LIBFT_PATH} all

clean:
	rm -f $(TARGET) $(OBJS)
	# FIX: UNCOMMENT LATER, DONE FOR TESTING PURPOUSE
	#
	# make -C ${LIBFT_PATH} fclean

fclean: clean
	rm -f $(TARGET) $(NAME)

re: fclean all

.PHONY: all clean fclean re
