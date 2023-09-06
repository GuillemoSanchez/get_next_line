NAME = get_next_line
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
CC = cc

SRC = 	get_next_line_utils.c \
		get_next_line.c 

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -c
	$(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all