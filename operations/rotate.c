#include "push_swap.h"
//ra (rotate a): Shift up all elements of stack a by one. The first element becomes the last one.
//rb (rotate b): Shift up all elements of stack b by one. The first element becomes the last one.
//rr : ra and rb at the same time 
void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack);
	*stack = (*stack)->next;
	tmp->next = NULL;
	add_back(stack, tmp);
}

void	rotate_ra(t_bench *bench, t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
	if (bench != NULL)
		++bench->moves[ra];
}

void	rotate_rb(t_bench *bench, t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
	if (bench != NULL)
		++bench->moves[rb];
}

void	rotate_rr(t_bench *bench, t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	if (bench != NULL)
		++bench->moves[rr];
}