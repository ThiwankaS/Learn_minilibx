NAME = art  # Choose a name for your executable
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -Iminilibx # Include path here
LDFLAGS = -Lminilibx -lmlx_Linux -lXext -lX11 -lm -lz # Libraries and library path

SRCS = art.c # Add other .c files here if needed
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
