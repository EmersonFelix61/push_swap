#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
} t_stack;

//typedef struct s_bench
//{
	//disorder
	//strategy
//}

int	parser_numbers(char *arg);
int	parser_range(char *arg);
int	parser_int(char *arg, int *number);
t_stack *new_stack(int value);
void    add_back(t_stack **stack, t_stack *new);
t_stack *stack_last(t_stack *stack);
void    stack_free(t_stack **stack);

#endif
