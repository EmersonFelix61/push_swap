/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 10:05:51 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 10:11:06 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_strategy	used_strategy;
	int			numbers_count;
	int			moves[11];
}	t_bench;

typedef struct s_radix
{
	int	*arr;
	int	size;
	int	bit;
}	t_radix;

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

/*--PARSERS--*/
int			parser_range(char *arg);
int			parser_numbers(char *arg);
void		free_tokens(char **tokens);
int			len_args(int argc, char **argv);
char		*join_args(int argc, char **argv);
int			parser_int(char *arg, int *number);
char		**get_tokens(int argc, char **argv);
int			is_duplicate(int *numbers, int size);
int			parser_flags(char **tokens, t_bench *bench);
int			*get_numbers(char **tokens, int numbers_count);
int			parser(int argc, char **argv, int **numbers, t_bench *bench);
int			set_strategy(t_bench *bench, char *token, int *strategy_tester);

/*--BENCH--*/
void		init_bench(t_bench *bench);
int			bench_moves(t_bench *bench);
void		print_bench(t_bench *bench);
void		print_moves(t_bench *bench);
char		*strategy_name(t_strategy strategy);
char		*strategy_complexity(t_bench *bench);
int			set_bench(t_bench *bench, char *token);
void		print_disorder_percent(double disorder);

/*--UTILS--*/
int			print_error(void);
char		*move_name(int move);
int			is_sorted(t_stack *stack);
int			stack_size(t_stack *stack);
int			*get_array(t_stack *stack);
int			*stack_to_array(t_stack *stack);
void		sort_array(int *array, int size);
int			find_min_position(t_stack *stack);
int			find_max_position(t_stack *stack);
int			get_position(t_stack *stack, int value);
void		move_min_top(t_bench *bench, t_stack **a);

t_stack		*new_stack(int value);
t_stack		*stack_last(t_stack *stack);
void		stack_free(t_stack **stack);
t_stack		*stack_before_last(t_stack *stack);
t_stack		*stack_builder(int *numbers, int size);
void		add_back(t_stack **stack, t_stack *new);

/*--OPERATIONS--*/
void		swap(t_stack **stack);
void		swap_sa(t_bench *bench, t_stack **a);
void		swap_sb(t_bench *bench, t_stack **b);
void		swap_ss(t_bench *bench, t_stack **a, t_stack **b);

void		push(t_stack **src, t_stack **dst);
void		push_pa(t_bench *bench, t_stack **a, t_stack **b);
void		push_pb(t_bench *bench, t_stack **a, t_stack **b);

void		rotate(t_stack **stack);
void		rotate_ra(t_bench *bench, t_stack **a);
void		rotate_rb(t_bench *bench, t_stack **b);
void		rotate_rr(t_bench *bench, t_stack **a, t_stack **b);

void		rev_rotate(t_stack **stack);
void		rev_rra(t_bench *bench, t_stack **a);
void		rev_rrb(t_bench *bench, t_stack **b);
void		rev_rrr(t_bench *bench, t_stack **a, t_stack **b);

/*--ALGORITHM--*/
double		ft_disorder(t_stack *stack);
void		sort_two(t_bench *bench, t_stack **a);
void		sort_three(t_bench *bench, t_stack **a);
void		sort_four(t_bench *bench, t_stack **a, t_stack **b);
void		sort_five(t_bench *bench, t_stack **a, t_stack **b);
void		picker_ra_rra(t_bench *bench, t_stack **a, int pos);
void		picker_rb_rrb(t_bench *bench, t_stack **b, int pos);
void		simple_sort(t_bench *bench, t_stack **a, t_stack **b);
void		medium_sort(t_bench *bench, t_stack **a, t_stack **b);
void		complex_sort(t_bench *bench, t_stack **a, t_stack **b);
t_strategy	adaptive_sort(t_bench *bench, t_stack **a, t_stack **b);
#endif
