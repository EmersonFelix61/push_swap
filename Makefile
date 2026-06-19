NAME = push_swap

BONUS_CHECKER_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPFLAGS = -MMD -MP

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
UTILS_DIR = utils
PARSERS_DIR = parsers
INC_DIR = includes
OPERATIONS_DIR = operations
ALGORITHM_DIR = algorithm
BENCH_DIR = bench
CHECKER_DIR = checker_files

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
	$(UTILS_DIR)/utils_algorith_2.c \
	$(OPERATIONS_DIR)/push.c \
	$(OPERATIONS_DIR)/rotate.c \
	$(OPERATIONS_DIR)/rev_rotate.c \
	$(OPERATIONS_DIR)/swap.c \
	$(ALGORITHM_DIR)/simple.c \
	$(ALGORITHM_DIR)/medium.c \
	$(ALGORITHM_DIR)/adaptive.c \
	$(ALGORITHM_DIR)/complex.c \
	$(ALGORITHM_DIR)/tiny.c \
	$(BENCH_DIR)/bench.c \
	$(BENCH_DIR)/print_bench.c \
	$(BENCH_DIR)/utils_bench.c \

SRCS_BONUS_CHECKER_NAME = \
	$(PARSERS_DIR)/parser_args.c \
	$(PARSERS_DIR)/parser_flags.c \
	$(PARSERS_DIR)/parser_tokens.c \
	$(PARSERS_DIR)/parser_input.c \
	$(UTILS_DIR)/stack_map.c \
	$(UTILS_DIR)/errors.c \
	$(UTILS_DIR)/stack_builder.c \
	$(UTILS_DIR)/stack.c \
	$(OPERATIONS_DIR)/push.c \
	$(OPERATIONS_DIR)/rotate.c \
	$(OPERATIONS_DIR)/rev_rotate.c \
	$(OPERATIONS_DIR)/swap.c \
	$(BENCH_DIR)/bench.c \
	$(BENCH_DIR)/utils_bench.c \
	get_next_line/get_next_line_bonus.c \
	get_next_line/get_next_line_utils_bonus.c \
	$(CHECKER_DIR)/checker_bonus.c \
	$(CHECKER_DIR)/checker_apply_instruction_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS_CHECKER_NAME = $(SRCS_BONUS_CHECKER_NAME:.c=.o)

DEPS = $(sort $(OBJS:.o=.d) $(OBJS_BONUS_CHECKER_NAME:.o=.d))

LIBFT_INPUTS = $(wildcard $(LIBFT_DIR)/*.c) \
	$(LIBFT_DIR)/libft.h \
	$(LIBFT_DIR)/Makefile

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS_CHECKER_NAME): $(LIBFT) $(OBJS_BONUS_CHECKER_NAME) 
	$(CC) $(CFLAGS) $(OBJS_BONUS_CHECKER_NAME) $(LIBFT) -o $(BONUS_CHECKER_NAME)
	
bonus: $(BONUS_CHECKER_NAME)

$(LIBFT): $(LIBFT_INPUTS)
	$(MAKE) re -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS_CHECKER_NAME) $(DEPS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_CHECKER_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
