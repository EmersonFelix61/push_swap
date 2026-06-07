#include "push_swap.h"
//sa (swap a): Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.
//sb (swap b): Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.
void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || ! *stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	swap_sa(t_bench *bench, t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
	if (bench != NULL)
		++bench->moves[sa];
}

void	swap_sb(t_bench *bench, t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
	if (bench != NULL)
		++bench->moves[sb];
}

void	swap_ss(t_bench *bench, t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	if (bench != NULL)
		++bench->moves[ss];
}
