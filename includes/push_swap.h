#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

typedef struct s_bench
{
	int			display;
	double		disorder;
	t_strategy	strategy;
	int			numbers_count;
	int			moves[11];
}	t_bench;

typedef enum e_moves
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_moves;

int		parser_numbers(char *arg);
int		parser_range(char *arg);
int		parser_int(char *arg, int *number);
int		is_duplicate(int *numbers, int size);
int		*get_numbers(char **tokens, int numbers_count);
int		len_args(int argc, char **argv);
char	*join_args(int argc, char **argv);
char	**get_tokens(int argc, char **argv);
void	free_tokens(char **tokens);
void	init_bench(t_bench *bench);
int		set_bench(t_bench *bench, char *token);
int		set_strategy(t_bench *bench, char *token, int *strategy_tester);
int		parser_flags(char **tokens, t_bench *bench);
int		parser(int argc, char **argv, int **numbers, t_bench *bench);

int	print_error(void);
int	stack_size(t_stack *stack);
int	is_sorted(t_stack *stack);
int	find_min_position(t_stack *stack);
int	find_max_position(t_stack *stack);
int	get_position(t_stack *stack, int value);

t_stack	*new_stack(int value);
void	add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_before_last(t_stack *stack);
void	stack_free(t_stack **stack);
t_stack	*stack_builder(int *numbers, int size);

void	swap(t_stack **stack);
void	swap_sa(t_bench *bench, t_stack **a);
void	swap_sb(t_bench *bench, t_stack **b);
void	swap_ss(t_bench *bench, t_stack **a, t_stack **b);

void	push(t_stack **src, t_stack **dst);
void	push_pa(t_bench *bench, t_stack **a, t_stack **b);
void	push_pb(t_bench *bench, t_stack **a, t_stack **b);

void	rotate(t_stack **stack);
void	rotate_ra(t_bench *bench, t_stack **a);
void	rotate_rb(t_bench *bench, t_stack **b);
void	rotate_rr(t_bench *bench, t_stack **a, t_stack **b);

void	rev_rotate(t_stack **stack);
void	rev_rra(t_bench *bench, t_stack **a);
void	rev_rrb(t_bench *bench, t_stack **b);
void	rev_rrr(t_bench *bench, t_stack **a, t_stack **b);

void	picker_ra_rra(t_bench *bench, t_stack **a, int pos);
void	move_min_top(t_bench *bench, t_stack **a);
void	simple_sort(t_bench *bench, t_stack **a, t_stack **b);

#endif
