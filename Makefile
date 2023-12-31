CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRCS = main.c printf_functions.c
OBJS = $(SRCS:.c=.o)

all: output

output: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o output

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f output

re: fclean all

.PHONY: all clean fclean re
