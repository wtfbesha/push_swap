NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

simple: fclean
	$(CC) $(CFLAGS) simple.c -o $(NAME)

medium: fclean
	$(CC) $(CFLAGS) medium.c -o $(NAME)

complex: fclean
	$(CC) $(CFLAGS) complex.c -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re simple medium complex
