NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Libft configurations
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_LINK = -L$(LIBFT_DIR) -lft

SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

all: $(LIBFT) $(NAME)

# Build libft using its own Makefile via target directory
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Link push_swap with libft.a
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LINK) -o $(NAME)

# Compile root object files and track header changes
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re