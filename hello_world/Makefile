NAME = hello_world
CC = gcc
CFLAGS = -Wall -Wextra -I/usr/include -Imlx_linux -O3 -g -fsanitize=address,undefined # -Wall -Wextra -Werror
LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#assuming the directory name containing the https://github.com/42Paris/minilibx-linux?tab=BSD-2-Clause-1-ov-file libry
# is mlx_linux

SRCS = hello_world.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean

.PHONY: all clean fclean re
