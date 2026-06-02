#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct	s_stack
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

typedef struct  s_bench
{
	int			display;
	double		disorder; 
	t_strategy	*strategy;
	int			moves[11];
	char		*big_o;
}	t_bench;

typedef struct s_config
{
	t_strategy	strategy;
	t_bench		*bench; //alterado
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

t_stack	*new_stack(int value);
void	add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_before_last(t_stack *stack);
void	stack_free(t_stack **stack);
t_stack *stack_builder(char **tokens);

void	swap(t_stack **stack);
void	sa(t_config *config, t_stack **a);
void	sb(t_config *config, t_stack **b);
void	ss(t_config *config, t_stack **a, t_stack **b);

void	push(t_stack **src, t_stack **dst);
void	pa(t_config *config, t_stack **a, t_stack **b);
void	pb(t_config *config, t_stack **a, t_stack **b);

void	rotate(t_stack **stack);
void	ra(t_config *config, t_stack **a);
void	rb(t_config *config, t_stack **b);
void	rr(t_config *config, t_stack **a, t_stack **b);

void	rev_rotate(t_stack **stack);
void	rra(t_config *config, t_stack **a);
void	rrb(t_config *config, t_stack **b);
void	rrr(t_config *config, t_stack **a, t_stack **b);
#endif
