NAME = gnl_test

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)

# Defines for buffer size, default 42
BUFFER_SIZE = 42

all: $(NAME)

$(NAME): $(OBJS) main.c
	$(CC) $(CFLAGS) $(OBJS) main.c -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test.txt

re: fclean all

.PHONY: all clean fclean re
