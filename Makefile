NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I. -I$(LIBFT_DIR)
LIBFT_LINK = -L$(LIBFT_DIR) -lft

SRCS = push_swap.c \
       parsing/parse_args.c \
       parsing/validate_args.c \
       parsing/init_stack.c \
       operations/push/pa.c \
       operations/push/pb.c \
       operations/rotate/ra.c \
       operations/rotate/rb.c \
       operations/rotate/rr.c \
       operations/reverse_rotate/rra.c \
       operations/reverse_rotate/rrb.c \
       operations/reverse_rotate/rrr.c \
       operations/swap/sa.c \
       operations/swap/sb.c \
       disorder/compute_disorder.c \
       strategies/simple.c \
       strategies/adaptive.c
       strategies/complex.c
       stack/stack_medium_utils.c \
       strategies/medium.c 

OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LINK) -o $(NAME)

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