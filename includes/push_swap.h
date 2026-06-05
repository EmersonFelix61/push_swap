# ifndef PUSH_SWAP_H
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
	t_strategy	*strategy;
	int			moves[11];
	char		*big_o;
}	t_bench;

typedef enum	e_moves
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

typedef struct s_config
{
	t_strategy	strategy;
	t_bench		*bench;
	int			numbers_count;
}	t_config;

int		parser_numbers(char *arg);
int		parser_range(char *arg);
int		parser_int(char *arg, int *number);
int		len_args(int argc, char **argv);
char	*join_args(int argc, char **argv);
char	**get_tokens(int argc, char **argv);
void	free_tokens(char **tokens);
int		print_error(void);
void	init_config(t_config *config, t_bench *bench);
int		set_bench(char *token, t_config *config);
int		set_strategy(char *token, t_config *config, int *strategy_found);
int		parser_flags(char **tokens, t_config *config);

t_stack	*new_stack(int value);
void	add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_before_last(t_stack *stack);
void	stack_free(t_stack **stack);
t_stack	*stack_builder(char **tokens);

void	init_bench(t_bench	*bench);

void	swap(t_stack **stack);
void	swap_sa(t_config *config, t_stack **a);
void	swap_sb(t_config *config, t_stack **b);
void	swap_ss(t_config *config, t_stack **a, t_stack **b);

void	push(t_stack **src, t_stack **dst);
void	push_pa(t_config *config, t_stack **a, t_stack **b);
void	push_pb(t_config *config, t_stack **a, t_stack **b);

void	rotate(t_stack **stack);
void	rotate_ra(t_config *config, t_stack **a);
void	rotate_rb(t_config *config, t_stack **b);
void	rotate_rr(t_config *config, t_stack **a, t_stack **b);

void	rev_rotate(t_stack **stack);
void	rev_rra(t_config *config, t_stack **a);
void	rev_rrb(t_config *config, t_stack **b);
void	rev_rrr(t_config *config, t_stack **a, t_stack **b);
#endif
