NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
UTILS_DIR = utils
PARSERS_DIR = parsers
INC_DIR = includes
OPERATIONS_DIR = operations
ALGORITHM_DIR = algorithm

SRCS = \
	$(SRC_DIR)/main.c \
	$(PARSERS_DIR)/parser_args.c \
	$(PARSERS_DIR)/parser_flags.c \
	$(PARSERS_DIR)/parser_tokens.c \
	$(PARSERS_DIR)/parser_input.c \
	$(UTILS_DIR)/stack_map.c \
	$(UTILS_DIR)/errors.c \
	$(UTILS_DIR)/stack_builder.c \
	$(UTILS_DIR)/stack.c \
	$(UTILS_DIR)/utils_algorithm.c \
	$(OPERATIONS_DIR)/push.c \
	$(OPERATIONS_DIR)/rotate.c \
	$(OPERATIONS_DIR)/rev_rotate.c \
	$(OPERATIONS_DIR)/swap.c \
	$(ALGORITHM_DIR)/simple.c \
	$(ALGORITHM_DIR)/medium.c \
	$(ALGORITHM_DIR)/adaptive.c \
	$(ALGORITHM_DIR)/complex.c \
	$(ALGORITHM_DIR)/tiny.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

RM = rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
